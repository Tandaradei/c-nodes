var margin, width, height;
var orientations, svg;

function init() {
  (margin = { top: 100, right: 10, bottom: 240, left: 10 }),
    (width = 340 - margin.left - margin.right),
    (height = 600 - margin.top - margin.bottom);
  console.log(margin);
  orientations = {
    "bottom-to-top": {
      size: [width, height],
      x: function(d) {
        return d.x;
      },
      y: function(d) {
        return d.y;
      }
    }
  };
  d3.select("svg#tree")
    .attr("width", width + margin.left + margin.right)
    .attr("height", height + margin.top + margin.bottom)
    .data(d3.entries(orientations))
    .enter();
  svg = d3
    .select("svg#tree")
    .append("g")
    .attr("transform", "translate(" + margin.left + "," + margin.top + ")");
}

function loadfile(file) {
  d3.json(file).then(plot);
}

function plot(data, expr) {
  console.log(expr);
  svg.each(function(orientation) {
    //var svg = d3.select(this);
    var o = orientation.value;
    console.log(orientations);
    var treemap = d3.tree().size(o.size);

    var nodes = d3.hierarchy(data);

    nodes = treemap(nodes);

    var links = nodes.descendants().slice(1);

    svg
      .selectAll("g")
      .data([])
      .join();
    svg
      .selectAll("circle")
      .data([])
      .join();
    svg
      .selectAll("text")
      .data([])
      .join();
    svg
      .selectAll("path")
      .data([])
      .join();

    svg
      .selectAll(".link")
      .data(links)
      .enter()
      .append("path")
      .attr("class", "link")
      .attr("d", function(d) {
        return (
          "M" +
          d.x +
          "," +
          o.y(d) +
          "C" +
          d.x +
          "," +
          (o.y(d) + o.y(d.parent)) / 2 +
          " " +
          d.parent.x +
          "," +
          (o.y(d) + o.y(d.parent)) / 2 +
          " " +
          d.parent.x +
          "," +
          o.y(d.parent)
        );
      });

    // Create the node circles.
    var node = svg
      .selectAll(".node")
      .data(nodes.descendants())
      .enter()
      .append("g");
    node
      .append("circle")
      .attr("class", function(d) {
        console.log(d.data.name);
        return "node " + d.data.type + " " + (d.data.processed ? "processed" : "unprocessed");
      })
      .attr("r", 10)
      .attr("cx", o.x)
      .attr("cy", o.y)
      .attr("opacity", function(d) {
        return  ;
      });

    node
      .append("text")
      .text(function(d) {
        return d.data.name;
      })
      .attr("x", o.x)
      .attr("dx", -3)
      .attr("dy", +3)
      .attr("y", o.y);

    node
      .append("text")
      .text(function(d) {
        return d.data.type !== "ERROR" ? d.data.result : "";
      })
      .attr("x", o.x)
      .attr("dx", -5)
      .attr("dy", -12)
      .attr("y", o.y);

      node
        .append("title")
        .text(function(d) {
          return d.data.error;
        })
  });
}

function test(h) {
  if (h == null) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        test(this.responseText);
      }
    };
    xhttp.open("POST", "c-expression-viewer.php", true);
    var params = {
      expr: document.getElementById("expr").value
    };
    if(vars.children.length > 0) {
      var symbols = "";
      console.log(vars);
      for(i in vars.children) {
        for(u in vars.children[i].children) {
          var td = vars.children[i].children[u];
          console.log(td);
          if(typeof td === "object" && td.children.length > 0) {
            var node = td.children[0];
            var value = node.type === "checkbox" ? 
              node.checked ? "1" : "0" :
              node.value;
            console.log(value);
            symbols += value +",";
          }
        }
        symbols = symbols.slice(0, symbols.length - 1);
        symbols += ";";
      }
      symbols = symbols.slice(0, symbols.length - 1);
      params["symbols"] = symbols;
    }
    console.log(params);
    xhttp.setRequestHeader("Content-type", "application/json");
    console.log(xhttp);
    xhttp.send(JSON.stringify(params));
  }
  else {
    console.log(h);
    var result = JSON.parse(h)
    plot(result.tree, result.expr);
  }
}

function addVariable() {
  vars = document.getElementById("vars");
  
  var new_var = document.createElement("tr");
  
  var identifier = document.createElement("input");
  identifier.setAttribute("type", "text");
  var identifier_td = document.createElement("td");
  identifier_td.appendChild(identifier);
  new_var.appendChild(identifier_td);

  var type = document.createElement("select");
  var opt_int = document.createElement("option");
  opt_int.setAttribute("value", "int");
  opt_int.text = "int";
  type.appendChild(opt_int);
  var opt_double = document.createElement("option");
  opt_double.setAttribute("value", "double");
  opt_double.text = "double";
  type.appendChild(opt_double);
  var type_td = document.createElement("td");
  type_td.appendChild(type);
  new_var.appendChild(type_td);
  
  var value = document.createElement("input");
  value.setAttribute("type", "text");
  var value_td = document.createElement("td");
  value_td.appendChild(value);
  new_var.appendChild(value_td);

  var is_const = document.createElement("input");
  is_const.setAttribute("type", "checkbox");
  var is_const_td = document.createElement("td");
  is_const_td.appendChild(is_const);
  new_var.appendChild(is_const_td);

  vars.appendChild(new_var);
}
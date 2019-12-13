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
        return "node " + d.data.type;
      })
      .attr("r", 10)
      .attr("cx", o.x)
      .attr("cy", o.y);

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
        return d.data.result;
      })
      .attr("x", o.x)
      .attr("dx", -5)
      .attr("dy", -12)
      .attr("y", o.y);
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

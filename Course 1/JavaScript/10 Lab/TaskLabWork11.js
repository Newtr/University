("use strict");
$(document).ready(function () {
  $("#colorchange").mouseover(function () {
    $("#colorchange").css("color", "red");
  });
  $("[src='Pictures/Cat_1.jpeg']").click(function () {
    $("[src='Pictures/Cat_1.jpeg']").attr("src", "Pictures/download.jpg");
  });
  $("#sizechange").click(function () {
    $("#sizechange").css("fontSize", "24px");
  });
  $("#text").click(function () {
    $("#text").html("<img src='Pictures/download.jpg'/>");
  });
  $("[src='Pictures/Cat_1.jpeg']").mouseover(function () {
    $(this).css("width", "250px");
  });
  $("[src='Pictures/Cat_1.jpeg']").mouseout(function () {
    $(this).css("width", "200px");
  });
  $("p").dblclick(function () {
    $(this).css("border", "outset 5px red");
  });
});

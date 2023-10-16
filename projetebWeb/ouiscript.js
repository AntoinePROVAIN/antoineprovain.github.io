
var diapoRolling = 0;
var currentImg = 0;
var nbImg = 3;
var images = ["images/mini.jpg", "images/mini1.jpg", "images/mini2.jpg"];
var myImg;

function initVar() {
    //alert ("hello");
    var diapoRolling = 0;
    var currentImg = 0;
    var nbImg = 3;
    var images = ["images/mini.jpg", "images/mini1.jpg", "images/mini2.jpg"];
    
    myImg = document.getElementById("myImg");
    //alert (myImg);
}

function prev() {
    currentImg--;
  if(currentImg < 0){
      currentImg = nbImg - 1;
  }
  myImg.src = images[currentImg];
}

function next() {
  currentImg++;
  if(currentImg > nbImg - 1){
      currentImg = 0;
  }
  myImg.src = images[currentImg];
}

function startstop(){
  if(diapoRolling==0){
      diapoRolling = 1;
  launch();
  } else {
      clearTimeout(myVar);
      diapoRolling = 0;
  }
}

function launch(){
  myVar = setTimeout(launch,2000);
      next();
}
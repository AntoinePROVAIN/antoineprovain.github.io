var x = 1;
//Fonction lancée au chargement de l'image Game Over qui s'appelle elle-même et qui alterne entre afficher et cacher l'image
function cligne() {
  if (x == 0) {
    document.getElementById("over").style.display = "none";
    x = 1;
  } else {
    document.getElementById("over").style.display = "block";

    x = 0;
  }

  setTimeout(cligne, 750);
}

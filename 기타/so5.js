function DarkMode() {
    const header = document.getElementById("header");
    const container = document.querySelector(".container");
    const footer = document.getElementById("footer");
    const p = document.querySelectorAll("p");
    const h4 = document.querySelectorAll("h4");
    const h5 = document.querySelectorAll("h5");
    const faqBtn = document.getElementById("faqBtn");
    const mainLogo = document.getElementById("mainLogo");
    let wantback = "black";
    let wantcolor = "white";
    let icon = "./img/Night.png"
    if(header.style.backgroundColor == "black"){
        wantback = "white";
          wantcolor = "black";
          icon = "./img/Day.png"
    }
    header.style.backgroundColor = wantback;
    container.style.backgroundColor = wantback;
    footer.style.backgroundColor = wantback;
    p.forEach(function (t) {
      t.style.color = wantcolor;
    });
    h4.forEach(function (t) {
      t.style.color = wantcolor;
    });
    h5.forEach(function (t) {
      t.style.color = wantcolor;
    });
    faqBtn.style.color = wantcolor;
    faqBtn.style.backgroundColor = wantback;
    mainLogo.src = icon;
  }
  
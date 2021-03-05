var i=0;
var sum=0;
var confirm_=true;
var lock=false;
function show(){
  document.getElementById("bin_window").style.display='block';
  document.getElementById("grey").style.display='block';
}
function not_show(){
  document.getElementById("bin_window").style.display='none';
  document.getElementById("window").style.display='none';
  document.getElementById("grey").style.display='none';
}
function offer(){
  document.getElementById("bin_window").style.display='none';
  document.getElementById("window").style.display='block';
  for(var j=0;j<i;++j){
    if(document.getElementById(j) != undefined ){
      document.getElementById(j).remove();
    }
  }
  sum=0;
  i=0;
  document.getElementById("sum_costs").innerText ="Общая цена: " + sum + " UAH";
  if(confirm_ == true){
    window.localStorage.clear();
    console.log("Данные в хранилище после оформления заказа!");
    console.log(localStorage.length);
  }
}
function buy(text, cost){
  if(lock == false){
    confirm_=confirm("Данный сайт использует локальное хранилище вашего браузера, для хранения списка покупок. Разрешить?");
    lock=true;
  }
  var new_div=document.createElement('div');
  var new_img=document.createElement('img');
  var new_font=document.createElement('font');
  var old_elem=document.getElementById('bin_window_window');
  new_div.className='bin_label';
  new_div.id=i;
  new_div.dataset.cost=cost;
  new_img.src="close.jpg";
  new_img.className='picture_to_right';
  new_img.width="50";
  new_img.style="margin-top: 15px;";
  ++i;
  new_img.addEventListener('click', function(event){
    var parent=document.getElementById(this.parentNode.id);
    var cost=parent.dataset.cost;
    document.getElementById(this.parentNode.id).remove();
    sum -= cost;
    document.getElementById("sum_costs").innerText ="Общая цена: " + sum + " UAH";
    if(confirm_ == true){
      localStorage.removeItem(this.parentNode.id);
    }
  });
  new_font.innerText=text;
  new_font.size="5";
  new_div.appendChild(new_font);
  new_div.appendChild(new_img);
  old_elem.appendChild(new_div);
  document.getElementById("bin_window").style.display='block';
  document.getElementById("grey").style.display='block';
  sum += cost;
  document.getElementById("sum_costs").innerText ="Общая цена: " + sum + " UAH";
  if(confirm_ == true){
    if (window.sessionStorage && window.localStorage){
      localStorage.setItem(i, text+ '/' +cost);
    }
    else{
      alert("Локальное хранилище не доступно!");
    }
    i++;
    localStorage.setItem("counter", i);
  }
}
window.addEventListener("load", function(event){
  if(confirm_ == true){
    i=Number(localStorage.getItem("counter"));
    for(var j=0; j < i; j++){
      if(localStorage.getItem(j) != undefined){
        var a="";
        var b=0;
        var from_localStorage=localStorage.getItem(j);
        do{
         a += from_localStorage[b];
         b++;
        } while(from_localStorage[b] !="/");
        var text=a;
        var cost=Number(from_localStorage.slice(a.length+1));
        var new_div=document.createElement('div');
        var new_img=document.createElement('img');
        var new_font=document.createElement('font');
        var old_elem=document.getElementById('bin_window_window');
        new_div.className='bin_label';
        new_div.id=j;
        new_div.dataset.cost=cost;
        new_img.src="close.jpg";
        new_img.className='picture_to_right';
        new_img.width="50";
        new_img.style="margin-top: 15px;";
        new_img.addEventListener('click', function(event){
          var parent=document.getElementById(this.parentNode.id);
          var cost=parent.dataset.cost;
          document.getElementById(this.parentNode.id).remove();
          sum -= cost;
          document.getElementById("sum_costs").innerText ="Общая цена: " + sum + " UAH";
          localStorage.removeItem(this.parentNode.id);
        });
        new_font.innerText=text;
        new_font.face="Times New Roman";
        new_font.size="5";
        new_div.appendChild(new_font);
        new_div.appendChild(new_img);
        old_elem.appendChild(new_div);
        document.getElementById("bin_window").style.display='block';
        document.getElementById("grey").style.display='block';
        sum += cost;
        document.getElementById("sum_costs").innerText ="Общая цена: " + sum + " UAH";
      }
    }
    console.log("Данные в хранилище после перезагрузки страницы!");
    console.log(localStorage.length);
  }
});

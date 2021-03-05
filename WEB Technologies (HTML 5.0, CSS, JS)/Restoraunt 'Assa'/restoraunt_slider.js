var slideIndex = 1;
/* Вызываем функцию, которая реализована ниже: */
showSlides(slideIndex);
 
/* Увеличиваем индекс на 1 — показываем следующий слайд: */
function nextSlide() {
    showSlides(slideIndex += 1);
}
 
/* Уменьшаем индекс на 1 — показываем предыдущий слайд: */
function previousSlide() {
    showSlides(slideIndex -= 1);  
}
 
/* Устанавливаем текущий слайд: */
function currentSlide(n) {
    showSlides(slideIndex = n);
}
 
/* Функция перелистывания: */
function showSlides(n) {
    /* Обращаемся к элементам с названием класса "slide", то есть к картинкам: */
    var slides = document.getElementsByClassName("slide");
    var dots = document.getElementsByClassName("dot");
    /* Проверяем количество слайдов: */
    if (n > slides.length) {
      slideIndex = 1
    }
    if (n < 1) {
        slideIndex = slides.length
    }
  
    /* Проходим по каждому слайду в цикле for: */
    for (var slide of slides) {
        slide.style.display = "none";
    }
    /* Делаем элемент блочным: */
    slides[slideIndex - 1].style.display = "block"; 
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    // slides[slideIndex - 1].style.display = "block";
    dots[slideIndex - 1].className += " active";   
}
 
/* Автообновление слайдера каждые 5 секунд спустя 4 секунды после обновления страницы: */
var timerId = setTimeout(function tick() {
    nextSlide();
    timerId = setTimeout(tick, 5000);
}, 4000);
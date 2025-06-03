// 1: console.log($); means it console the JQuery and $ is the syantax of JQuery:

// 2: $('selector').action();  JQuery syantax:

// 3: $("p").click(); means the p element clicked when document load:

// 4: means when clicked on p element then the fucntion executed:
// $("p").click(function () {
//  console.log("Clicked");
// });

// 5: console.log("Thanks" , this); this means it show the selected, clicked, hovered element:

// 6: $('p').hide(); .hide() means it hide the selected class,id or element:

// 7: $("p").show(); .show() means it show the selected class,id or element:

// 8: There are Three types of selector in Jquery:
// $('p').click();  element selector
// $('#id').click();  id selector
// $('.class').click();  class selector

// 9: other selecotor:
// ('*').click(); means it click on all element:
// ('p:first').click(); means it triggered the first element:
// ('p:last').click(); means it triggered the last element:

// 10: Events in JQuery:
// Mouse events = click, dblclick, mouseenter, mouseleave
// Keyboard events = keypress, keydown, MediaKeyStatusMap
// form events = submit, change, focus, blur
// document/window events = load, resize, scroll, unload

// 11: $(this).toggle();.toggle() means it hide or show the selected class,id or element:

// 12: document.ready means first html document load then the sript load and running we use $(document).ready(function(){}) or simple $(function(){}):
// $(document).ready(function () {
//     $("p").click(function () {
//       console.log("Clicked");
//       $(this).hide();
//     });
// });

// 13: demoing the on method in JQuery, the on method also take two events, and also attach multiple events on one element:
// $(document).ready(function () {
//   $('p').on(
//   {
//     click:
//       function () {
//         console.log("Thanks", this);
//       },

//     mouseleave:
//       function () {
//         console.log("Goodbye", this);
//       }
//   }
// )});

// 14: .hide(1000, function(){}) , .show(1000,function() {}), .toogle(1000, function() {}) : hide, show, toogle function the selected element, id, class and it take two arguments time,  callback function. It means it hide, show, toggle the selected element within the given speed argument and run a callback function:
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').toggle(1000 , function () {
//             alert("HIDE");
//         });
//     })
// })

// 15: JQuery Fade Function. There 4 types of fade method: All of these fade function take two arguments first is (time or speed) and second is callback function:
// fadeIn();
// fadeOut();
// fadeTo();
// fadeToggle();
// fadeIn();
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').fadeIn(1000 , function () {
//             alert("Fade-In");
//         });
//     })
// })
// fadeOut();
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').fadeOut(1000 , function () {
//             alert("Fade-Out");
//         });
//     })
// })
// fadeToggle();
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').fadeToggle(1000 , function () {
//             alert("Fade-Toggle");
//         });
//     })
// })
// fadeTo();
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').fadeTo(1000 , function () {
//             alert("Fade-Toggle");
//         });
//     })
// })

// 16: JQuery Slide Function. There are three method in slide function. All of these slide function take two arguments first is speed and second is callback function:
// slideDown();
// slideUp();
// slideToggle();
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').slideUp(1000 , function () {
//             alert("Slide-Method");
//         });
//         $('#paragraph').slideDown(1000 , function () {
//             alert("Slide-Method");
//         });
//         $('#paragraph').slideToggle(1000 , function () {
//             alert("Slide-Method");
//         });
//     })
// })

// 17: Jquery Animate Function. it takes multiple parameters like opacity, height etc. lastly it take time like 2000 or speed like slow,fast as a parameter:
// $(document).ready(function () {
//     $('#btn').click(function () {
//         $('#paragraph').animate({
//             opacity: 0.3,
//             width:"350px",
//         },"slow")
//     })

// Queud Functionnality:
// $('#btn').click(function () {
// $('#paragraph').animate({opacity: 0.3},3000);  First run this:
// $('#paragraph').animate({width: "130px"},1000); Second run this:
// $('#paragraph').animate({height: "30px"},4000); Third run this:
// })
// })

//  18: JQuery stop() function:
// $(document).ready(function () {
//     $('#btn').on(
//         {
//         click: function () {
//                 $('#paragraph').animate({opacity: 0.3},3000);
//                 $('#paragraph').animate({width: "130px"},12000);
//                 $('#paragraph').animate({height: "30px"},4000);
//             }
//         }
//     )

//     $('#paragraph').on(
//         {
//         mouseenter: function () {
//                 $('#paragraph').stop();
//             }
//         }
//     )
// })

// 19: JQuery Dom function. .text() , .html() :
// $(document).ready(function () {
//     console.log($('#paragraph').text());  .text() function means it display the text inside the element:
//     console.log($('#paragraph').text("I am Foxy")); .text("I am Foxy") means it console the element in the form of object and change text with given text and display it on html document:

//     console.log($("body").html("")); .html() function means it display the entire element:
//     console.log($("body").html("<h1>FOXY</h1>")); .html("I am Foxy") means it console the element in the form of object and change html element with given element and display it on html document:
// })

// 20: JQuery Form Function. .val(), empty() is used for input, textarea and it used only for change the value of input, textarea tag:
// $(document).ready(function () {
// console.log($("#myTextArea").val()); It display the value of textarea
// console.log($("#myTextArea").val("Hellow")); It display the  textarea in the form of object and change value and display it on html document
// console.log($("#myTextArea").empty()); It empty the value of textarea
// });

// 21 JQuery remove function: it remove the selected element, id, class from the dom (document):
// $(document).ready(function () {
//     console.log($("#myTextArea").remove()); It remove the element from the entire document:
// });

// 22 JQuery add and remove class function: it add and remove class:
// $(document).ready(function () {
//     $("#myTextArea").addClass('.wiki'); It add class to the selected element, id, class:
//     $("#myTextArea").removeClass('.wiki'); It remove class to the selected element, id, class:
//     $("#myTextArea").toggleClass('.wiki');  if class already added It remove the class, and if class already removed it add the class to the selected element, id, class:
// });

// 23 JQuery css function : it add the css in the selected element, id, class:
// $(document).ready(function () {
// $("#paragraph").css('color','red'); It add class to the selected element, id, class:
// });

// 24 Main JQuery point: Ajax (Ajax means Art of exchanging data with a server without reloading the page), (communicate with the server and manipulate the dom(data object model) without reloading the page).
// $.get("https://code.jquery.com/jquery-3.7.1.js",function(data, status){
//     alert(data);
// });
// $.get("https://code.jquery.com/jquery-3.7.1.js",function(data, status){
//     alert(status);
// });
// $.post("https://code.jquery.com/jquery-3.7.1.js",{
//         name:"fahad",
//         channed:"wwww.google.pk",
//         age:"18",
// },function(data, status){alert(status);})

// 25: JQuery .queue() and .dequeue() function:
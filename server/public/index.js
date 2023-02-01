 //for local running in terminal type ipconfig and use that ip idress in mobile  make sure both server and mobile are connectedto same hostnameg
  

var map_init = L.map('map', {
    center: [23.814296468133172, 86.44118417874446],
   
 
    zoom: 16.5,
    markerZoomAnimation :true,
});
map_init.zoomControl.remove();
L.control.zoom({
    position: 'bottomright'
}).addTo(map_init);


var osm = L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    //attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
    attribution: 'and <a href="http://127.0.0.1:5501/server/public/admin.html">click me</a>' 
}).addTo(map_init);




if(!navigator.geolocation) {
    console.log("Your browser doesn't support geolocation feature!")
} else {
    setInterval(() => {
        navigator.geolocation.getCurrentPosition(getPosition)
    }, 5000);
}








var marker, circle, lat, long, accuracy;

function getPosition(position) {
    // console.log(position)
    lat = position.coords.latitude
    long = position.coords.longitude
    accuracy = position.coords.accuracy

    if (marker) {
        map_init.removeLayer(marker)
    }

    if (circle) {
        map_init.removeLayer(circle)
    }

    marker = L.marker([lat, long])
   
   circle = L.circle([lat, long], { radius: accuracy })

    // var featureGroup = L.featureGroup([ marker]).addTo(map_init)
    // map_init.flyTo([lat,long],18,{
    //     animate : true,
    //     duration : 1,
    // })

    // map_init.fitBounds(featureGroup.getBounds())
    

    console.log("Your coordinate is: Lat: " + lat + " Long: " + long + " Accuracy: " + accuracy)




 
}








// we uses from for sending data since we dont need to add headers etc if form everything is handled by js and html themselves





function showResults(val) {
  res = document.getElementById("result");
  res.innerHTML = '';
  if (val == '') {
    return;
  }
  let list = '';
  fetch('/suggest?q=' + val).then(
   function (response) {
     return response.json();
   }).then(function (data) {
     for (i=0; i<data.length; i++) {
       list += ' <ul class="innerulist">' + data[i] + '</ul>';
       
     }
     res.innerHTML = ' <ul class="ulist" >' + list + '</ul> ';




  document.querySelector('ul').addEventListener("click", (e)=>{
   // console.log(e.target.innerHTML);
  

   
   
   searchBtn=document.querySelector('.search-suggestions');
     searchBtn.value = e.target.innerText;
     document.querySelector('.search-suggestions').addEventListener("onkeyup", (e)=>{
      showResults()
     })
   
        
});



  
  

  



     return true;
   }).catch(function (err) {
     console.warn('Something went wrong.', err);
     return false;
   });
}

/*document.querySelector('.search-btn').addEventListener('click',(e)=>{
    const inp=document.querySelector('#input').value;
    console.log(inp)
    
    })*/
  

 // Create a new routing control instance
let control = L.Routing.control({
  waypoints: [
   
  ]
}).addTo(map_init);

// Function to update the route
function updateRoute(waypoints) {
 

    // Remove the previous route
    if (control) {
      control.remove();
    }
   
  // Add a new routing control instance with updated waypoints
  let control = L.Routing.control({
    waypoints: waypoints
  }).addTo(map_init);

 

}


  
  
  
  


let placeData;
document.querySelector('.icon').addEventListener('click',()=>{

  
   let point=document.querySelector('.search-suggestions').value;
 
 
  fetch(`/maproute/${point}`).then((response)=>{return response.json()}).then((data)=>{
    placeData=data;
    console.log(placeData[0].latitude,placeData[0].longitude)
   
    })


//     //Call the function with updated waypoints
 updateRoute([

  // L.latLng(51.5, -0.1),
  // L.latLng(51.51, -0.1)
  L.latLng(23.814296468133172, 86.44118417874446),
  L.latLng(placeData[0].latitude,placeData[0].longitude)
 ]);
 


  });

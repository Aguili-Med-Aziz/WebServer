function fetchSensorData() {
  fetch('/getSensorData')
    .then(response => response.json())
    .then(data => {
      document.getElementById('sensorData').innerHTML = `
        Temperature: ${data.temperature} °C<br>
        Humidity: ${data.humidity} %<br>
        Light: ${data.light} lux<br>
        Pressure: ${data.pressure} hPa
      `;
    });
}

function updateMotorSpeed() {
  const speed = document.getElementById('motorSpeedSlider').value;
  fetch(`/setMotorSpeed?speed=${speed}`)
    .then(response => response.text())
    .then(message => alert(message));
}

setInterval(fetchSensorData, 1000);  // Fetch sensor data every second

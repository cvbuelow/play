(function() {
  var ball = document.createElement('div'),
    t = 0,
    dt = 0.3,
    y,
    g = -9.81,
    h = 100,
    dh = -20,
    animate = function() {
      y = g*t*t + h;
      if (y >= 0) {
        t += dt;
      } else {
        h += dh;
        y = 0;
        t = -Math.sqrt((y - h) / g);
      }
      ball.style.bottom = y + '%';
      if (h > 0) {
        setTimeout(animate, 60);
      }
    };
    ball.style.borderRadius = '50px';
    ball.style.position = 'fixed';
    ball.style.left = '50%';
    ball.style.backgroundColor = 'red';
    ball.style.width = '100px';
    ball.style.height = '100px';
    document.body.appendChild(ball);
    animate();
})();
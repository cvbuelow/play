const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false
});

let num = 0;
rl.on('line', function(line) {
  if (!num) {
    return num++;
  }
  let one = 0;
  let two = 0;
  for (let i = 0; i < line.length; i++) {
    const power = Math.pow(10, line.length - i - 1);
    if (line[i] === "4") {
      one += 3 * power;
      two += 1 * power;
    } else {
      one += parseInt(line[i]) * power;
    }
  }
  console.log(`Case #${num++}: ${one} ${two}`);
});

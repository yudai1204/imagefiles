"use strict";
function main(lines) {
  if (lines[0] === "1") {
    step1(lines);
  } else if (lines[0] === "2") {
    step2(lines);
  } else if (lines[0] === "3") {
    step3(lines);
  } else if (lines[0] === "4") {
    step4(lines);
  }
}

function runWithStdin() {
  let input = "";
  process.stdin.resume();
  process.stdin.setEncoding("utf8");

  process.stdin.on("data", (v) => {
    input += v;
  });
  process.stdin.on("end", () => {
    main(input.split("\n"));
  });
}

// runWithStdin();

main(
  `
`.split("\n")
);

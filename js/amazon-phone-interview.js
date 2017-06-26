// A 2D map is represented as an integer matrix where 0s are traversible and 1s are obstacles.
// Given a starting position (row, column) compute the size of reachable area.

//1 1 0 0 0 1
//1 0 0 1 1 1
//1 1 0 0 0 1
//0 1 1 1 1 1
//0 0 1 1 1 1

// Starting point (1, 2)
// Expected result -> 8

// Test case:
// map: [[0, 0]]
// starting point: [0, 0]
// Expected output: 2

function findReachableArea(map, startingPoint) {

  function isReachable(point) {
    return map[point[0]][point[1]] === 0;
  }

  if (!isReachable(startingPoint)) {
    return 0;
  }

  function analyzePoint(point) {
    let area = 0;

    if (isReachable(point)) {
      map[point[0]][point[1]] = 2;
      area += 1;
    } else {
      return 0;
    }

    const topRow = point[0] - 1;
    if (topRow >= 0 && isReachable([topRow, point[1]])) {
      area += analyzePoint([topRow, point[1]]);
    }

    const bottomRow = point[0] + 1;
    if (bottomRow < map.length && isReachable([bottomRow, point[1]])) {
      area += analyzePoint([bottomRow, point[1]]);
    }

    const leftCol = point[1] - 1;
    if (leftCol >= 0 && isReachable([point[0], leftCol])) {
      area += analyzePoint([point[0], leftCol]);
    }

    const rightCol = point[1] + 1;
    if (rightCol < map[point[0]].length && isReachable([point[0], rightCol])) {
      area += analyzePoint([point[0], rightCol]);
    }
    return area;
  }

  return analyzePoint(startingPoint);
}

var findLargestProductOfTwoNumbers = function(numbers) {
  var largest = 0;
  var secondLargest = 0;
  var largestNegative = 0;
  var secondLargestNegative = 0;

  numbers.forEach(function(number) {
    if (number > 0) {
      if (number > largest) {
        secondLargest = largest;
        largest = number;
      } else if (number > secondLargest) {
        secondLargest = number;
      }
    } else {
      if (number < largestNegative) {
        secondLargestNegative = largestNegative;
        largestNegative = number;
      } else if (number < secondLargestNegative) {
        secondLargestNegative = number;
      }
    }
  });

  if (largest * secondLargest > largestNegative * secondLargestNegative) {
    return [largest, secondLargest];
  } else {
    return [largestNegative, secondLargestNegative];
  }

};
for( var i = 0; i < 10; i++ ) {
  window.setTimeout( (function(x) {
    console.log( x );
  })(i), 0 );
}


// <mydatepicker date="10/10/2015" />

// --> 

// <input type="text" value="10/10/2015">
// $(el).datepicker();

angular.module('myDatePicker', [])
    .directive('mydatepicker', function() {
        return {
            template: '<input type="text" value="{{val}}">',
            scope: {
                date: '=date'
            },
            link: function($scope, element, attrs) {
                $scope.val = attrs.date;
                angular.element(element).datepicker({
                    change: function(newval) {
                        $scope.val = newval;
                        $scope.$digest();
                    }
                });
            }
        };
    });
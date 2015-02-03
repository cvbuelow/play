(function() {
  var tree = [];

  var addBranch = function(limb) {
    var shouldAdd = Math.round(Math.random() - (limb.length * 0.1));
    if (shouldAdd) {
      limb.push([]);
    }
  };
  
  var grow = function(limb) {
    addBranch(limb);
    limb.forEach(grow);
  };

  var interate = function() {

    var addNode = function(parent) {
      var div = document.createElement('div');
      parent.appendChild(div);
      return div;
    };

    var draw = function(limbs, ele) {
      limbs.forEach(function(limb) {
        draw( limb, addNode(ele) );
      });
    };

    grow(tree);
    document.body.innerHTML = '';
    draw(tree, document.body);

    setTimeout(interate, 1000);
  };

  interate();

})();
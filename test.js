
descre('plus', function() {
  it('should pass', function() {
    expect(true).toBe(true);
  });

  it('should work', function() {
    expect(plus(1, 2)).toBe(3);
  });
  
  it('should work', function() {
	    expect(plus(5, 4)).toBe(9);
	  });
});



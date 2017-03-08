'use strict';
var mocha = require('mocha');
var expect = require('expect');

const addon = require('../build/Release/addon');

var obj = new addon.stringLowLevelLibWrapper();



describe('Native String Lookup Map', function() {
    it('should be empty string', function() {
        expect(obj.length()).toBe(0);
    });

    it('should be non empty string', function() {
        obj.set('lalal');
        expect(obj.get()).toBe('lalal');
        expect(obj.length()).toBe(5);
    });

    it('should clear string', function() {
        obj.clear();
        expect(obj.get()).toBe('');
        expect(obj.length()).toBe(0);
    });

    it('should append string', function() {
        obj.clear();
        obj.append("la");
        expect(obj.length()).toBe(2);

        obj.append("mi");
        expect(obj.length()).toBe(4);

        obj.append("do");
        expect(obj.length()).toBe(6);
    });

    it('should chunk string', function() {
        expect(obj.chunk(0, 2)).toBe("la");
        expect(obj.chunk(2, 2)).toBe("mi");
        expect(obj.chunk(4, 2)).toBe("do");
        expect(() => { obj.chunk(-3, 6) }).toThrow();
    })

    it('should regex string', function() {
        expect(obj.regex("l")).toBe(true);
        expect(obj.regex("m")).toBe(true);
        expect(obj.regex("o")).toBe(true);
        expect(obj.regex("([aid])")).toBe(true);

        expect(obj.regex("z")).toBe(false);
    })

});
import QtQuick 2.0
import QtTest 1.0
import QtQuick.Window 2.2
import "../src/" 1.00

TestCase {
    name: "tst_helloworld"

    HelloWorld {
        id: helloWorld
        textThing: "Hello World!"
    }

    function quickPOINT(function_name, point) {
        console.info("TMC:" + function_name + "." + point);
    }

    function test_world() {
        quickPOINT("tst_helloworld::test_world", "world_point");
        compare(helloWorld.textThing, "Hello World!")
    }
}

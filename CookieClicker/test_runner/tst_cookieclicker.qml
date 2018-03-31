import QtQuick 2.6
import QtTest 1.0
import QtQuick.Window 2.2

Item {
    id: container
    width: 400
    height: 400

    TestCase {
        id: cookieTest
        name: "tst_cookieClicker"
        when: windowShown

        SignalSpy {
            id: spy
        }

	function qml_POINT (exercise_name, point) {
            console.info("TMC:test_cookie_click.1")
        }

        function test_cookie_click() {
            qml_POINT(test_cookie_click, 1);
            var component = Qt.createComponent("CookieClickerTest.qml")
            compare(component.status, Component.Ready)
            var cookie = component.createObject(container);

            verify(cookie !== null, "cookie created is null")
            waitForRendering(cookie)

            cookie.forceActiveFocus()

            spy.target = cookie
            spy.signalName = "clickChanged"

            compare(spy.count, 0, "We have not clicked yet, but property click changed")
            mouseClick(cookie, 100, 100, Qt.LeftButton)
            compare(spy.count, 1, "Property click did not change when we clicked")
            compare(cookie.click, 1, "Property click did not change when we clicked")

            cookie.destroy()
        }

        function test_cookie_text() {
            var component = Qt.createComponent("CookieClickerTest.qml")
            compare(component.status, Component.Ready)
            var cookie = component.createObject(container);

            verify(cookie !== null, "cookie created is null")
            waitForRendering(cookie)

            cookie.forceActiveFocus()

            mouseClick(cookie, 100, 100, Qt.LeftButton)
            compare(cookie.click, 1, "Number of clicks should be 1")
            compare(cookie.status.text, "Chocolate cookies clicked: 1", "Status text should reflect the state of clicked cookies")
            mouseClick(cookie, 100, 100, Qt.LeftButton)
            compare(cookie.click, 2)
            compare(cookie.status.text, "Chocolate cookies clicked: 2", "Status text should follow the number of clicks")

            cookie.destroy()
        }
    }

}

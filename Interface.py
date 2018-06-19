import sys
from PyQt5.QtCore import QUrl
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWebEngineWidgets import QWebEngineView

class Interface(object):
    """The Gui for the AI
    
    Attributes:
        app: An object representing a Q application
    """

    def __init__(self):
        self.app = QApplication(sys.argv)

    def run(self):
        view = QWebEngineView()
        view.show()
        view.setUrl(QUrl("https://google.com"))
        self.app.exec()
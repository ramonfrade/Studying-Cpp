python

import sys, os.path

# Load kdevelop printers
sys.path.append(os.path.join(os.getcwd(), ".vscode", "gdb", "kdedevelop"))
from qt import register_qt_printers
register_qt_printers (None)

# Load qt6renderer printers
sys.path.append(os.path.join(os.getcwd(), ".vscode", "gdb", "qt6renderer"))
import qt6renderer
gdb.pretty_printers.append(qt6renderer.qt6_lookup)

end

set print pretty on

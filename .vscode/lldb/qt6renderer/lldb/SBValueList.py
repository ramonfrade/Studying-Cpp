from typing import Union

from .SBError import SBError
from .SBValue import SBValue


class SBValueList:
    def Append(self, val: Union[SBValue, 'SBValueList']): ...

    def Clear(self): ...

    def FindValueObjectByUID(self, uid: int) -> SBValue: ...

    def GetError(self) -> SBError: ...

    def GetFirstValueByName(self, name: str) -> SBValue: ...

    def GetSize(self) -> int: ...

    def GetValueAtIndex(self, idx: int) ->  SBValue: ...

    def IsValid(self) -> bool: ...
from typing import List

from .SBError import SBError
from .SBTarget import SBTarget


class SBData:
    byte_order: int
    double: List[float]
    doubles: List[float]
    float: List['float']
    floats: List['float']
    sint16: List[int]
    sint16s: List[int]
    sint32: List[int]
    sint32s: List[int]
    sint64: List[int]
    sint64s: List[int]
    sint8: List[int]
    sint8s: List[int]
    uint16: List[int]
    uint16s: List[int]
    uint32: List[int]
    uint32s: List[int]
    uint64: List[int]
    uint64s: List[int]
    uint8: List[int]
    uint8s: List[int]

    def Append(self, rhs: 'SBData'): ...

    def Clear(self): ...

    @staticmethod
    def CreateDataFromCString(endian: int, addr_byte_size: int, data: str) -> 'SBData': ...

    @staticmethod
    def CreateDataFromDoubleArray(endian: int, addr_byte_size, array: List['float']) -> 'SBData': ...

    @classmethod
    def CreateDataFromInt(value, size: int = None, target: SBTarget = None, ptr_size: int = None, endian: int = None) -> 'SBData': ...

    @staticmethod
    def CreateDataFromSInt32Array(endian: int, addr_byte_size: int, array: List[int]) -> 'SBData': ...

    @staticmethod
    def CreateDataFromSInt64Array(endian: int, addr_byte_size: int, array: List[int]) -> 'SBData': ...

    @staticmethod
    def CreateDataFromUInt32Array(endian: int, addr_byte_size: int, array: List[int]) -> 'SBData': ...

    @staticmethod
    def CreateDataFromUInt64Array(endian: int, addr_byte_size: int, array: List[int]) -> 'SBData': ...

    def GetAddress(self, error: SBError, offset: int) -> int: ...

    def GetAddressByteSize(self) -> int: ...

    def GetByteOrder(self) -> int: ...

    def GetByteSize(self) -> int: ...

    def GetDescription(self, description: 'SBStream', base_addr: int = 18446744073709551615) -> bool: ...

    def GetDouble(self, error: SBError, offset: int) -> 'float': ...

    def GetFloat(self, error: SBError, offset: int) -> 'float': ...

    def GetLongDouble(self, error: SBError, offset: int) -> 'float': ...

    def GetSignedInt16(self, error: SBError, offset: int) -> int: ...

    def GetSignedInt32(self, error: SBError, offset: int) -> int: ...

    def GetSignedInt64(self, error: SBError, offset: int) -> int: ...

    def GetSignedInt8(self, error: SBError, offset: int) -> int: ...

    def GetString(self, error: SBError, offset: int) -> str: ...

    def GetUnsignedInt16(self, error: SBError, offset: int) -> int: ...

    def GetUnsignedInt32(self, error: SBError, offset: int) -> int: ...

    def GetUnsignedInt64(self, error: SBError, offset: int) -> int: ...

    def GetUnsignedInt8(self, error: SBError, offset: int) -> int: ...

    def IsValid(self) -> bool: ...

    def ReadRawData(self, error: SBError, offset: int, buf: List[int]) -> int: ...

    def SetAddressByteSize(self, addr_byte_size: int): ...

    def SetByteOrder(self, endian: int): ...

    def SetData(self, error: SBError, buf: List[int], endian: int, addr_size: int): ...

    def SetDataFromCString(self, data: str) -> bool: ...

    def SetDataFromDoubleArray(self, array: List['float']) -> bool: ...

    def SetDataFromSInt32Array(self, array: List[int]) -> bool: ...

    def SetDataFromSInt64Array(self, array: List[int]) -> bool: ...

    def SetDataFromUInt32Array(self, array: List[int]) -> bool: ...

    def SetDataFromUInt64Array(self, array: List[int]) -> bool: ...

    def SetDataWithOwnership(self, error: SBError, buf: List[int], endian: int, addr_size: int) -> bool: ...

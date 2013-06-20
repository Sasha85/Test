;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                                                       ;
;       My first implementation of the "Lehmer random number generator" procedure, written in fasm      ;
;       Copyright (c) 2012,2013 Alexander Yefremov                                                      ;
;                                                                                                       ;
;       This program is free software: you can redistribute it and/or modify                            ;
;       it under the terms of the GNU Affero General Public License as published by                     ;
;       the Free Software Foundation, either version 3 of the License, or                               ;
;       (at your option) any later version.                                                             ;
;                                                                                                       ;
;       This program is distributed in the hope that it will be useful,                                 ;
;       but WITHOUT ANY WARRANTY; without even the implied warranty of                                  ;
;       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                   ;
;       GNU Affero General Public License for more details.                                             ;
;                                                                                                       ;
;       You should have received a copy of the GNU Affero General Public License                        ;
;       along with this program.  If not, see <http://www.gnu.org/licenses/>.                           ;
;                                                                                                       ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;       You must set the X_0 variable to initial seed
;       It returns a random number in eax register
;       See http://en.wikipedia.org/wiki/Lehmer_random_number_generator for details

Rand:
        mov   eax,[X_0]         ;       X[0]
        mov   ecx,3961633963    ;       g
        mul   ecx               ;       (edx:eax)=eax*operand
        mov   ecx,4294967291    ;       n
        div   ecx               ;       eax=(edx:eax)/operand ; edx=(edx:eax) mod operand
        mov   [X_0],edx
        mov   eax,edx           ;       if you want this procedure to return the number in edx, delete this line. It'll even be faster
        ret

        X_0 dd 0

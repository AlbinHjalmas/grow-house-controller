; Listing generated by Microsoft (R) Optimizing Compiler Version 19.11.25507.1 

	TITLE	C:\Users\Hjalm\Documents\Embedded\TouchGFX_Projects\GrowHouseController\generated\fonts\src\ApplicationFontProvider.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

PUBLIC	?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ; ApplicationFontProvider::getFont
EXTRN	?getFont_verdana_17_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_verdana_17_8bpp
EXTRN	?getFont_segoeui_67_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_segoeui_67_4bpp
EXTRN	?getFont_verdana_12_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_verdana_12_4bpp
EXTRN	?getFont_verdana_34_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_verdana_34_4bpp
EXTRN	?getFont_verdana_46_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_verdana_46_4bpp
EXTRN	?getFont_segoeui_40_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_segoeui_40_8bpp
EXTRN	?getFont_segoeui_18_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_segoeui_18_8bpp
EXTRN	?getFont_segoeui_28_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_segoeui_28_8bpp
EXTRN	?getFont_segoeui_17_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ:PROC ; getFont_segoeui_17_8bpp
EXTRN	__RTC_CheckEsp:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
;	COMDAT ?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z
_TEXT	SEGMENT
tv65 = -208						; size = 4
_this$ = -8						; size = 4
_fontId$ = 8						; size = 2
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z PROC ; ApplicationFontProvider::getFont, COMDAT
; _this$ = ecx
; File c:\users\hjalm\documents\embedded\touchgfx_projects\growhousecontroller\generated\fonts\src\applicationfontprovider.cpp
; Line 22
	push	ebp
	mov	ebp, esp
	sub	esp, 208				; 000000d0H
	push	ebx
	push	esi
	push	edi
	push	ecx
	lea	edi, DWORD PTR [ebp-208]
	mov	ecx, 52					; 00000034H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	pop	ecx
	mov	DWORD PTR _this$[ebp], ecx
; Line 23
	movzx	eax, WORD PTR _fontId$[ebp]
	mov	DWORD PTR tv65[ebp], eax
	cmp	DWORD PTR tv65[ebp], 8
	ja	SHORT $LN13@getFont
	mov	ecx, DWORD PTR tv65[ebp]
	jmp	DWORD PTR $LN15@getFont[ecx*4]
$LN4@getFont:
; Line 27
	call	?getFont_verdana_17_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_verdana_17_8bpp
	jmp	SHORT $LN1@getFont
$LN5@getFont:
; Line 30
	call	?getFont_segoeui_67_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_segoeui_67_4bpp
	jmp	SHORT $LN1@getFont
$LN6@getFont:
; Line 33
	call	?getFont_verdana_12_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_verdana_12_4bpp
	jmp	SHORT $LN1@getFont
$LN7@getFont:
; Line 36
	call	?getFont_verdana_34_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_verdana_34_4bpp
	jmp	SHORT $LN1@getFont
$LN8@getFont:
; Line 39
	call	?getFont_verdana_46_4bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_verdana_46_4bpp
	jmp	SHORT $LN1@getFont
$LN9@getFont:
; Line 42
	call	?getFont_segoeui_40_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_segoeui_40_8bpp
	jmp	SHORT $LN1@getFont
$LN10@getFont:
; Line 45
	call	?getFont_segoeui_18_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_segoeui_18_8bpp
	jmp	SHORT $LN1@getFont
$LN11@getFont:
; Line 48
	call	?getFont_segoeui_28_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_segoeui_28_8bpp
	jmp	SHORT $LN1@getFont
$LN12@getFont:
; Line 51
	call	?getFont_segoeui_17_8bpp@@YAAAVInternalFlashFont@touchgfx@@XZ ; getFont_segoeui_17_8bpp
	jmp	SHORT $LN1@getFont
$LN13@getFont:
; Line 54
	xor	eax, eax
$LN1@getFont:
; Line 56
	pop	edi
	pop	esi
	pop	ebx
	add	esp, 208				; 000000d0H
	cmp	ebp, esp
	call	__RTC_CheckEsp
	mov	esp, ebp
	pop	ebp
	ret	4
	npad	2
$LN15@getFont:
	DD	$LN4@getFont
	DD	$LN5@getFont
	DD	$LN6@getFont
	DD	$LN7@getFont
	DD	$LN8@getFont
	DD	$LN9@getFont
	DD	$LN10@getFont
	DD	$LN11@getFont
	DD	$LN12@getFont
?getFont@ApplicationFontProvider@@UAEPAVFont@touchgfx@@G@Z ENDP ; ApplicationFontProvider::getFont
_TEXT	ENDS
END

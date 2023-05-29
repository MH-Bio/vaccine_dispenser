<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="16" fill="1" visible="no" active="no"/>
<layer number="3" name="Route3" color="17" fill="1" visible="no" active="no"/>
<layer number="4" name="Route4" color="18" fill="1" visible="no" active="no"/>
<layer number="5" name="Route5" color="19" fill="1" visible="no" active="no"/>
<layer number="6" name="Route6" color="25" fill="1" visible="no" active="no"/>
<layer number="7" name="Route7" color="26" fill="1" visible="no" active="no"/>
<layer number="8" name="Route8" color="27" fill="1" visible="no" active="no"/>
<layer number="9" name="Route9" color="28" fill="1" visible="no" active="no"/>
<layer number="10" name="Route10" color="29" fill="1" visible="no" active="no"/>
<layer number="11" name="Route11" color="30" fill="1" visible="no" active="no"/>
<layer number="12" name="Route12" color="20" fill="1" visible="no" active="no"/>
<layer number="13" name="Route13" color="21" fill="1" visible="no" active="no"/>
<layer number="14" name="Route14" color="22" fill="1" visible="no" active="no"/>
<layer number="15" name="Route15" color="23" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="ERA-6AEB304V">
<packages>
<package name="RESC2012X60N">
<text x="-1.71" y="-1.02" size="0.5" layer="27" align="top-left">&gt;VALUE</text>
<text x="-1.71" y="1.02" size="0.5" layer="25">&gt;NAME</text>
<wire x1="1.1" y1="-0.68" x2="-1.1" y2="-0.68" width="0.127" layer="51"/>
<wire x1="1.1" y1="0.68" x2="-1.1" y2="0.68" width="0.127" layer="51"/>
<wire x1="1.1" y1="-0.68" x2="1.1" y2="0.68" width="0.127" layer="51"/>
<wire x1="-1.1" y1="-0.68" x2="-1.1" y2="0.68" width="0.127" layer="51"/>
<wire x1="-1.708" y1="-0.94" x2="1.708" y2="-0.94" width="0.05" layer="39"/>
<wire x1="-1.708" y1="0.94" x2="1.708" y2="0.94" width="0.05" layer="39"/>
<wire x1="-1.708" y1="-0.94" x2="-1.708" y2="0.94" width="0.05" layer="39"/>
<wire x1="1.708" y1="-0.94" x2="1.708" y2="0.94" width="0.05" layer="39"/>
<smd name="1" x="-0.925" y="0" dx="1.06" dy="1.38" layer="1"/>
<smd name="2" x="0.925" y="0" dx="1.06" dy="1.38" layer="1"/>
</package>
</packages>
<symbols>
<symbol name="ERA-6AEB304V">
<wire x1="-5.08" y1="0" x2="-4.445" y2="1.905" width="0.254" layer="94"/>
<wire x1="-4.445" y1="1.905" x2="-3.175" y2="-1.905" width="0.254" layer="94"/>
<wire x1="-3.175" y1="-1.905" x2="-1.905" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.905" y1="1.905" x2="-0.635" y2="-1.905" width="0.254" layer="94"/>
<wire x1="-0.635" y1="-1.905" x2="0.635" y2="1.905" width="0.254" layer="94"/>
<wire x1="0.635" y1="1.905" x2="1.905" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.905" y1="-1.905" x2="3.175" y2="1.905" width="0.254" layer="94"/>
<wire x1="3.175" y1="1.905" x2="4.445" y2="-1.905" width="0.254" layer="94"/>
<wire x1="4.445" y1="-1.905" x2="5.08" y2="0" width="0.254" layer="94"/>
<text x="-7.624440625" y="2.54148125" size="2.54148125" layer="95">&gt;NAME</text>
<text x="-7.62996875" y="-5.086640625" size="2.54331875" layer="96">&gt;VALUE</text>
<pin name="1" x="-10.16" y="0" visible="off" length="middle" direction="pas"/>
<pin name="2" x="10.16" y="0" visible="off" length="middle" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="ERA-6AEB304V" prefix="R">
<description>ERA Series 0805 300 kO ±0.1 % 0.125 W ±25 ppm/°C Molded Thin Film Chip Resistor</description>
<gates>
<gate name="G$1" symbol="ERA-6AEB304V" x="0" y="0"/>
</gates>
<devices>
<device name="" package="RESC2012X60N">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="Unavailable"/>
<attribute name="DESCRIPTION" value=" 300 kOhms ±0.1% 0.125W, 1/8W Chip Resistor 0805 _2012 Metric_ Automotive AEC-Q200 Thin Film  "/>
<attribute name="MF" value="Panasonic"/>
<attribute name="MP" value="ERA-6AEB304V"/>
<attribute name="PACKAGE" value="2012 Panasonic Electronic Components"/>
<attribute name="PRICE" value="None"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="TMP36GRTZ-REEL7">
<packages>
<package name="SOT95P280X145-5N">
<description>&lt;b&gt;Small Outline Package&lt;/b&gt; Fits JEDEC packages (narrow SOIC-8)</description>
<circle x="-2.8134" y="1.0094" radius="0.1" width="0.2" layer="51"/>
<text x="-2.44343125" y="-3.305709375" size="1.27" layer="27">&gt;VALUE</text>
<text x="-2.44253125" y="1.98" size="1.27" layer="25">&gt;NAME</text>
<wire x1="-0.85" y1="1.5" x2="-0.85" y2="-1.5" width="0.127" layer="51"/>
<wire x1="-0.85" y1="-1.5" x2="0.85" y2="-1.5" width="0.127" layer="51"/>
<wire x1="0.85" y1="-1.5" x2="0.85" y2="1.5" width="0.127" layer="51"/>
<wire x1="-0.85" y1="1.5" x2="0.85" y2="1.5" width="0.127" layer="51"/>
<wire x1="-0.85" y1="1.564" x2="0.85" y2="1.564" width="0.127" layer="21"/>
<wire x1="0.85" y1="-1.564" x2="-0.85" y2="-1.564" width="0.127" layer="21"/>
<wire x1="-1.1" y1="1.75" x2="1.1" y2="1.75" width="0.05" layer="39"/>
<wire x1="-1.1" y1="-1.75" x2="1.1" y2="-1.75" width="0.05" layer="39"/>
<wire x1="-2.11" y1="1.5" x2="-2.11" y2="-1.5" width="0.05" layer="39"/>
<wire x1="2.11" y1="1.5" x2="2.11" y2="-1.5" width="0.05" layer="39"/>
<wire x1="-1.1" y1="1.5" x2="-2.11" y2="1.5" width="0.05" layer="39"/>
<wire x1="-1.1" y1="1.75" x2="-1.1" y2="1.5" width="0.05" layer="39"/>
<wire x1="1.1" y1="-1.5" x2="2.11" y2="-1.5" width="0.05" layer="39"/>
<wire x1="1.1" y1="-1.75" x2="1.1" y2="-1.5" width="0.05" layer="39"/>
<wire x1="-1.1" y1="-1.75" x2="-1.1" y2="-1.5" width="0.05" layer="39"/>
<wire x1="1.1" y1="1.75" x2="1.1" y2="1.5" width="0.05" layer="39"/>
<wire x1="-1.1" y1="-1.5" x2="-2.11" y2="-1.5" width="0.05" layer="39"/>
<wire x1="1.1" y1="1.5" x2="2.11" y2="1.5" width="0.05" layer="39"/>
<circle x="-2.8134" y="1.0094" radius="0.1" width="0.2" layer="21"/>
<smd name="1" x="-1.165" y="0.95" dx="1.39" dy="0.6" layer="1" roundness="50"/>
<smd name="2" x="-1.165" y="0" dx="1.39" dy="0.6" layer="1" roundness="50"/>
<smd name="3" x="-1.165" y="-0.95" dx="1.39" dy="0.6" layer="1" roundness="50"/>
<smd name="4" x="1.165" y="-0.95" dx="1.39" dy="0.6" layer="1" roundness="50" rot="R180"/>
<smd name="5" x="1.165" y="0.95" dx="1.39" dy="0.6" layer="1" roundness="50" rot="R180"/>
</package>
</packages>
<symbols>
<symbol name="TMP36GRTZ-REEL7">
<wire x1="-12.7" y1="7.62" x2="12.7" y2="7.62" width="0.254" layer="94"/>
<wire x1="12.7" y1="7.62" x2="12.7" y2="-7.62" width="0.254" layer="94"/>
<wire x1="12.7" y1="-7.62" x2="-12.7" y2="-7.62" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-7.62" x2="-12.7" y2="7.62" width="0.254" layer="94"/>
<text x="-12.7127" y="8.14201875" size="1.782459375" layer="95">&gt;NAME</text>
<text x="-12.7076" y="-9.917090625" size="1.78068125" layer="96">&gt;VALUE</text>
<pin name="GND" x="15.24" y="-5.08" length="short" direction="pwr" rot="R180"/>
<pin name="+VS" x="15.24" y="5.08" length="short" direction="pwr" rot="R180"/>
<pin name="VOUT" x="15.24" y="0" length="short" direction="out" rot="R180"/>
<pin name="!SHUTDOWN" x="-17.78" y="0" length="middle" direction="in"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="TMP36GRTZ-REEL7" prefix="U">
<description>Temp Sensor Analog(Voltage) Serial (2-Wire) 5-Pin Sot-23 T/R</description>
<gates>
<gate name="G$1" symbol="TMP36GRTZ-REEL7" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SOT95P280X145-5N">
<connects>
<connect gate="G$1" pin="!SHUTDOWN" pad="4"/>
<connect gate="G$1" pin="+VS" pad="2"/>
<connect gate="G$1" pin="GND" pad="5"/>
<connect gate="G$1" pin="VOUT" pad="1"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="Unavailable"/>
<attribute name="DESCRIPTION" value=" Temperature Sensor Analog, Local -40°C ~ 125°C 10mV/°C SOT-23-5 "/>
<attribute name="MF" value="Analog Devices"/>
<attribute name="MP" value="TMP36GRTZ-REEL7"/>
<attribute name="PACKAGE" value="SOT-23-5 Analog Devices"/>
<attribute name="PRICE" value="None"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="my-library">
<packages>
</packages>
<symbols>
</symbols>
<devicesets>
<deviceset name="53426-0310">
<gates>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="my-library" urn="urn:adsk.eagle:library:18644167">
<packages>
<package name="53426-0310" urn="urn:adsk.eagle:footprint:18644168/1" library_version="1" library_locally_modified="yes">
<pad name="P$1" x="-2.5" y="0" drill="0.66"/>
<pad name="P$2" x="0" y="0" drill="0.66"/>
<pad name="P$3" x="2.5" y="0" drill="0.66"/>
<wire x1="-5" y1="-2.75" x2="5.25" y2="-2.75" width="0.127" layer="21"/>
<wire x1="-5" y1="-2.75" x2="-5" y2="8.75" width="0.127" layer="21"/>
<wire x1="-5" y1="8.75" x2="5.25" y2="8.75" width="0.127" layer="21"/>
<wire x1="5.25" y1="8.75" x2="5.25" y2="-2.75" width="0.127" layer="21"/>
<text x="-3" y="-4.5" size="1.27" layer="21">1</text>
<text x="-0.5" y="-4.5" size="1.27" layer="21">2</text>
<text x="2" y="-4.5" size="1.27" layer="21">3</text>
</package>
</packages>
<packages3d>
<package3d name="53426-0310" urn="urn:adsk.eagle:package:18644170/1" type="box" library_version="1" library_locally_modified="yes">
<packageinstances>
<packageinstance name="53426-0310"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="53426-0310" urn="urn:adsk.eagle:symbol:18644169/1" library_version="1" library_locally_modified="yes">
<pin name="P$1" x="-10.16" y="17.78" length="middle" rot="R180"/>
<pin name="P$2" x="-10.16" y="10.16" length="middle" rot="R180"/>
<pin name="P$3" x="-10.16" y="2.54" length="middle" rot="R180"/>
<rectangle x1="-10.16" y1="0" x2="2.54" y2="20.32" layer="94"/>
<text x="-10.16" y="-2.54" size="1.778" layer="94">53426-0310</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="53426-0310" urn="urn:adsk.eagle:component:18644171/1" locally_modified="yes" library_version="1" library_locally_modified="yes">
<gates>
<gate name="G$1" symbol="53426-0310" x="-68.58" y="12.7"/>
</gates>
<devices>
<device name="" package="53426-0310">
<connects>
<connect gate="G$1" pin="P$1" pad="P$1"/>
<connect gate="G$1" pin="P$2" pad="P$2"/>
<connect gate="G$1" pin="P$3" pad="P$3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:18644170/1"/>
</package3dinstances>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<modules>
<module name="TMP36" prefix="" dx="30.48" dy="20.32">
<ports>
</ports>
<variantdefs>
</variantdefs>
<parts>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
</instances>
<busses>
</busses>
<nets>
</nets>
</sheet>
</sheets>
</module>
</modules>
<parts>
<part name="R1" library="ERA-6AEB304V" deviceset="ERA-6AEB304V" device=""/>
<part name="U1" library="TMP36GRTZ-REEL7" deviceset="TMP36GRTZ-REEL7" device=""/>
<part name="U$6" library="my-library" library_urn="urn:adsk.eagle:library:18644167" deviceset="53426-0310" device="" package3d_urn="urn:adsk.eagle:package:18644170/1"/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="R1" gate="G$1" x="53.34" y="66.04" smashed="yes">
<attribute name="NAME" x="45.715559375" y="68.58148125" size="2.54148125" layer="95"/>
<attribute name="VALUE" x="45.71003125" y="60.953359375" size="2.54331875" layer="96"/>
</instance>
<instance part="U1" gate="G$1" x="5.08" y="68.58" smashed="yes">
<attribute name="NAME" x="-7.6327" y="76.72201875" size="1.782459375" layer="95"/>
<attribute name="VALUE" x="-7.6276" y="58.662909375" size="1.78068125" layer="96"/>
</instance>
<instance part="U$6" gate="G$1" x="93.98" y="55.88" smashed="yes"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="VOUT"/>
<pinref part="R1" gate="G$1" pin="1"/>
<wire x1="20.32" y1="68.58" x2="43.18" y2="68.58" width="0.1524" layer="91"/>
<wire x1="43.18" y1="68.58" x2="43.18" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="+VS"/>
<pinref part="U$6" gate="G$1" pin="P$1"/>
<wire x1="20.32" y1="73.66" x2="83.82" y2="73.66" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="GND"/>
<wire x1="20.32" y1="63.5" x2="40.64" y2="63.5" width="0.1524" layer="91"/>
<wire x1="40.64" y1="63.5" x2="40.64" y2="58.42" width="0.1524" layer="91"/>
<pinref part="U$6" gate="G$1" pin="P$3"/>
<wire x1="40.64" y1="58.42" x2="83.82" y2="58.42" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="R1" gate="G$1" pin="2"/>
<pinref part="U$6" gate="G$1" pin="P$2"/>
<wire x1="63.5" y1="66.04" x2="83.82" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>

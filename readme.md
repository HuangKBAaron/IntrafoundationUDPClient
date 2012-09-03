<html>
<head>
<title>Intrafoundation.UDPClient.2 COM v2.2</title>
</head>

<body index="index.html">

<table border=0 cellspacing=0 cellpadding=0 width="100%" class=header>
<tr>
	<td colspan=2 align=right width=80%>
	<div><strong><a href="http://www.intrafoundation.com/software/udpclient.htm">I n t r a f o u n d a t i o n . U D P C l i e n t . 2</a></strong></div>
	</td>
	<td align=right width=20% rowspan=2><a href="index.html"></a></td>
</tr>
<tr>
	<td align=left>
<div class=headeroptional><!--C# .NET and -->C++ ATL COM Component</div>
<div class=headeroptional>FOR <a href="http://www.microsoft.com">ASP</a> and <a href="http://www.adobe.com">ColdFusion</a></div>
	</td>
	<td align=right>
<div></div>
<div><small>Open Source <!--64-bit .NET and -->64 and 32-bit C++ COM Object</small></div>
	</td>
</tr>
</table>
<table border=0 cellspacing=0 cellpadding=0 width=100%>
<tr valign=top>
	<td width=80%>

<table width=100%>
<tr valign=top>
	<td rowspan=4 width=360 class=logo></td>
	<td align=right>
	by <strong>Lewis Sellers</strong> (aka TommyRaven)<br>
	I n t r a f o u n d a t i o n   S o f t w a r e<br>

	<br>
	<br>
	
<tt><strong>v2.2, August 30th 2012</strong></tt><br>
<small>
<a href="http://www.intrafoundation.com">http://www.intrafoundation.com</a><br>
<a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a><br>
</small>

<br>
<div style="color: #800000; font-family: Arial,serif; font-size: 80%;">
I'm available for short and long term contract work.<br>
Need extensions of some kind crafted or an extra pair of hands for straight up web programming? <a href="http://www.intrafoundation.com/contact-us/">Contact Me</a>.
</div>
	</td>
</tr>
</table>


<div style="background-color: #f0f020; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<strong>NOTICE:</strong> This software is now <b>64-bit</b>. If you need <b>32-bit</b> builds, they are located in the <tt>32bit_versions\</tt> folder.
</div>
<div style="background-color: #f0f060; font-size: 9pt; text-align: center; margin: 1px; padding: 3px;">
<b>NEW:</b> Follow the open source development of this software at <a href="https://github.com/lasellers">lasellers @ github.com</a>
or <a href="http://www.codeplex.com/site/users/view/lasellers">lasellers @ codeplex.com</a>.
</div>




<!-- DESCRIPTION -->
<p class=firstpara>
This <strong>UDPClient</strong> COM object allows you to talk to anything on the Internet that uses the UDP communications protocol.
</p>
<p>
UDP is part of the TCP/IP suite which powers the internet and is the "little brother" of the more famous TCP.
UDP is an "unreliable connection-less" packet protocol.
This means you can send small "post-it note" like messages very, very quickly between machines but there is no guarentee that the message will ever arrive.
Compare this to TCP, which is slower to startup, but any data you send is automatically error-corrected and resent if lost along the way.
TCP also lets you send a stream of essentially unlimited size, where UDP is limited to about 65,507 bytes at the most.
</p>
<p>
A COM object
(for those of you who are using this software who are not web developers but hardcore gamers)
is a type of .DLL.
This particular type is the kind that makes up most of the code that powers the Windows Operating System itself.
They are essentially self-contained ("encapulated, object-oriented" in tech-speak) programs.
Many of the applications you may use (the .EXE files) will make use of COM objects that it brings with it or that are included with the Windows Operating System.
</p>
<p>
Primarily the only things of real importance these days that use UDP are:
</p>
<ol>
<li>Game servers(!) such as:
 <a href="http://www.idsoftware.com">Quake</a>,
 <a href="http://www.sierrastudios.com/games/half-life/">Half-Life</a>,
 <a href="http://www.epicgames.com">Unreal</a>,
 <a href="http://www.wheeloftime.com">Wheel of Time</a>,
 Baldur's Gate,
 Diablo,
 Star Trek : Elite Forces,
 et al (well, perhaps not ALL, but most the ones that anyone cares about).</li>
<li>Hardware-based routers (i.e., CISCOs).</li>
<li>Packet messagers such as ICQ.</li>
</ol>
<p>
For that reason most of the example code you will find here deals with the interrogation of on-line game servers.
(Did I hear a small cheer go up?)
</p>
<p>
Understand that this COM object provides only the elemental, base functionality you need to talk to these UDP servers.
As for what you're supposed to say to them and what do the messages they send back mean, well...
that's a subject for several heated on-line forum discussions and a half-dozen small project groups to ferret out.
I've included example scripts written in <A href="http://www.alliare.com">ColdFusion</a> meta-language (i.e, the files with those .cfm extensions) that show exactly how to talk to all the games I know how to talk to.
You'll have to figure the rest out yourselves.
Start by reading a games' official (or unofficial) protocol documents, if any... the rest is up to people willing to pester developers for the information or hackers with packet sniffers and a little imagination.
</p>



<br>
<br>
<br>
<h3>REQUIREMENTS / SERVER PLATFORMS</h3>
<p>
This COM object was originally designed on and for Windows 2000 Professional and Windows XP Professional.
The 2012 version and up was rebuilt on Windows 7 64-bit.
It has not been tested under Windows 95, 98, ME or NT 3.51/4.
Nevertheless, it may work under some of them.
</p>
<p>
Additionally you most typically will need either <a href="http://www.adobe.com">Adobe ColdFusion</a> or <a href="http://www.microsoft.com">Microsoft ASP</a> installed.
If you don't know what either of these are... 
then you're going to need to make friends with a geeky web developer somewhere to help you.
</p>
<p>
You should be able to use the COM from:
<ul>
<li>Adobe <a href="http://www.adobe.com">ColdFusion</a>
<li>Microsoft <A href="www.microsoft.com">ASP</a>
<li><a href="http://www.php4.net">PHP4</a>
<li>Any other engine or compiler that can use COM objects.
</ul>
</p>




<br>
<br>
<br>
<h3>INSTALLATION</h3>
<p>
The COM object itself is the file called <tt>UDPClientcom.dll</tt>.
To install it, at the command prompt type: <tt>regsvr32 UDPClientcom.dll</tt>.
You may first wish to copy it to your project folder or some other folder you make just for it.
</p>
<p>
The precompiled file <tt>UDPClientcom.dll</tt> is root folder of the archive.
</p>
<p>
There are install.bat and uninstall.bat files included that you can simply click from Windows which will do the same.
</p>



<br>
<br>
<br>
<h3>UNINSTALLATION</h3>
<p>
At the command prompt type: <tt>regsvr32 /u UDPClientcom.dll</tt>.
Or see above.
</p>




<br>
<br>
<br>
<h3>THE EXAMPLE SCRIPTS</h3>
<p>
There are several example scripts included with this COM object.
Some are only partially done.
None are optimised for the protocols they use.
Addtionally, some are written by the author(s) of this software, whlie others have been developed by it's users.
</p>
<p>
For most of the examples you'll need to have the appropriate SERVER software installed on your local computer
(i.e., either ASP or ColdFusion).
</p>
<p>
You might want to look at the source of the scripts before you use them.
</p>
<p>
You do not need to set this up for the COM object -- only to use some of the localhost examples.
And you should be connected to the internet for some of them as they talk to other machines out there.
</p>
<p>
If you are not connected to the Internet then the tag may sit there for several several seconds waiting for a name server to answer it.
</p>
<br>
<p>
<em>Send in your own sample scripts.</em>
</p>
<br>
<br>
<br>


<h3>FIREWALLS</h3>
<p>
Firewalls.
It's almost impossible these days to safely be connected to your local area network, let alone the Internet,
without using a firewall (and a half dozen other anti-viral, anti-trojan, anti-spyware, etc programs).
We bring this up because, most likely, you're using this software via a web server such as Microsoft IIS or Apache.
This means this COM object will be talking to the network through THEM in some fashion.
You won't be getting a simple software message stating that say, Intrafoundation.TCPClient or Intrafoundation.UDPClient, etc
are wishing access to the network.
</p>
<p>
You will in fact most likely get this message:<br>
<tt>(10061) (Connection refused. No connection could be made because the target machine actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host - i.e. one with no server application running.)</tt><br>
</p>
<p>
So no, you're going to have to specifically set up your firewall to allow network communication for this software.
With IIS in the default configuration ("Medium" Application Protection) this would theoretically mean enabling the infamous dllhost.dll, known as "COM Surrogate".
We say it's infamous because it's been used in a variety of ways by numerous viruses, worms, trojans and the like.
So much so that most software firewalls that have application protection will disable it by default.
</p>
<p>
If you set IIS Application Protection to "Low" it uses a process other than dllhost.dll, but low isn't generally a recommended setting.
When set to "High", against it uses a different process to run scripts through, namely Internet Information Services.
</p>
<p>
For a more detailed explaination of this topic, refer to your particular Web Server and Firewall manuals for exact information on this subject.
</p>
<br>
<br>
<br>


<h3>COPYRIGHT / TERMS OF USE</h3>
<p>
This software is Copyright (c) 2000, 2001, 2003, 2004 by Lewis A. Sellers.
It is not public domain, nor is it GPL'ed, but it is very close.
As long as you do not modify any files in the archive, nor add to them, nor delete any of them,
and do not charge for access to said archive you may redistribute the archive as you like.
</p>
<p>
You may use this software as-is with any software you wish, so long as said
archive is included unmodified with proper credits and link to it's homesite is included also
(<a href="http://www.intrafoundation.com/software/udpclient.htm">http://www.intrafoundation.com/software/udpclient.htm</a>).
</p>
<p>
You may modify and use the source code as you like -- with the understanding
that if you do, you still have to include the original, unaltered archive as
well as the aforementioned credits and link.
</p>
<p>
You may use this software in commerical applications, whether closed-source or open-source so long as the aforementioned unaltered archive is included with the application
and the aforementioned creditation and hyperlink are included.
</p>
<p>
If this software is used in a released project or included in a publication you are to make reasonable efforts to contact the author and notify them as to such.
The author of this software has a primary email address of: <a href="mailto:webmaster@intrafoundation.com">webmaster@intrafoundation.com</a>.
</p>
<p>
You use this software at your own risk.
</p>




<br>
<br>
<br>
<h3>COMMAND OVERVIEW : MAKING IT WORK</h3>

<table align=right>
<tr>
	<td align=right>
	
<table border=1 align=right class=function>
<tr><th colspan=3>METHODS</th></tr>
<tr><th>NAME</th><th>IN</th><th>OUT</th></tr>
<tr><td>Open</td><td>string "host", string "port"</td><td>boolean "connected"</td></tr>
<tr><td>Close</td><td>string "host", string "port"</td><td>boolean "connected"</td></td></tr>
<tr><td>Send</td><td>string "text"</td></tr>
<tr><td>Recv</td><td></td><td>string</td></tr>
<tr><td>SendCSV</td><td>string "csv"</td></tr>
<tr><td>RecvCSV</td><td>string "csv"</td></tr>
<tr><td>SendPacket</td><td></td></tr>
<tr><td>RecvPacket</td><td></td></tr>
<tr><td>addpacketnumber</td><td>type, number</td></tr>
<tr><td>addpacketchar</td><td>character</td></tr>
<tr><td>addpacketstring</td><td>string</td></tr>
<tr><td>addpacketipport</td><td>string "ip", string "port"</td></tr>
<tr><td>packetnumber</td><td>string "type"</td><td>number</td></tr>
<tr><td>packetstring</td><td></td><td>string</td></tr>
<tr><td>packetcharacter</td><td></td><td>character</td></tr>
<tr><td>packetipport</td><td></td><td>string "ip:port"</td></tr>
<tr><td>packetEOF</td><td>boolean</td></tr>
<tr><td>is_connected</td><td>boolean</td></tr>
<tr><td>packetclear</td><td></td></tr>
<tr><td>packetreposition</td><td>integer (0-65506)</td></tr>
<tr><td>ClearLog</td><td></td<td></td></tr>
</table>
<br clear=right>
<br clear=right>

<table border=1 align=right class=function>
<tr><th colspan=2>PROPERTIES (PUT)</th></tr>
<tr><td>timeout</td><td>floating-point-number "seconds"</td></tr>
</table>
<br clear=right>
<br clear=right>

<table border=1 align=right class=function>
<tr><th colspan=2>PROPERTIES (GET, only when connected)</th></tr>
<tr><td>timeout</td><td>floating-point-number "seconds"</td></tr>
<tr><td>localaddress</td><td>string + : + number</td></tr>
<tr><td>remoteaddress</td><td>string + : + number</td></tr>
<tr><td>bytessent</td><td>number "bytes"</td></tr>
<tr><td>bytesreceived</td><td>number "bytes"</td></tr>
<tr><td>kbpssending</td><td>floating-point-number</td></tr>
<tr><td>kbpsreceiving</td><td>floating-point-number</td></tr>
<tr><td>senttimeout</td><td>floating-point-number</td></tr>
<tr><td>receivedtimeout</td><td>floating-point-number</td></tr>
<tr><td>packetposition</td><td>integer (0-65506)</td></tr>
<tr><td>packetlength</td><td>integer (0-65536)</td></tr>
<tr><td>ping</td><td>integer "milliseconds"</td></tr>
</table>
<br clear=right>
<br clear=right>

<table border=1 align=right class=function>
<tr><th colspan=2>PROPERTIES (GET, anytime)</th></tr>
<tr><td>thread</td><td></td><td>number</td></tr>
<tr><td>version</td><td></td><td>string</td></tr>
<tr><td>copyright</td><td></td><td>string</td></tr>
<tr><td>description</td><td></td><td>string</td></tr>
<tr><td>instance</td><td></td><td>number</td></tr>
<tr><td>instances</td><td></td><td>number</td></tr>
<tr><td>Log</td><td></td><td>string</td></tr>
<tr><td>sendlength</td><td>number "bytes"</td></tr>
<tr><td>recvlength</td><td>number "bytes"</td></tr>
<tr><td>messagelength</td><td>number "bytes"</td></tr>
<tr><td>buffersize</td><td>number "bytes"</td></tr>
</table>
<br clear=right>
<br clear=right>

	</td>
</tr>
</table>

<p>
All right then, how the devil do you use it?
</p>

<p>
Well, assuming you installed/registered the COM object and on the same machine you've got ColdFusion or ASP installed then all you need to do is... open your browser to this web page and click on any of the examples to see it in living action.
(On the server... not as a file. That is with "HTTP://" prepended not "FILE://". But I really hope you knew that already.)
</p>
<p>
Assuming you've seen the examples and are now suitably excited about bringing this kind of thing to your own web pages -- read on.
</p>
<p>
Basically all there is to using this COM object is you open a UDP connect and then send and receive whateever UDP packets of data are required to get the information you require.
Then you close the connection.
</p>
<p>
There are several other useful properties you can look at or set that can be used for error handling and tweaking overall performance.
</p>
<p>
One thing that can not be stressed enough about this COM object though is that is
understands nothing about the higher-level application protocols.
The functions are generic.
They just tansfer the data, not interpret it.
</p>
<p>
How big a block of data can this transfer?
65507 bytes.
Maximum.
This is inherent to the UDP protocol itself.
</p>

<strong>DEALING WITH BINARY DATA</strong><br>
<p>
A lot of things you can talk to with UDP use plain text because that is,
as demonstratied by the telnet service, a fairly easy way to communicate.
However, some servers like the game Half-Life sends data in a pure C-Struct like binary format.
To deal with this several new functions were added as of 1.2.
They are:
</p>
<ul>
<li>SendPacket</li>
<li>RecvPacket</li>
<li>packetposition</li>
<li>packetlength</li>
<li>packetreposition</li>
<li>packetEOF</li>
<li>packetclear</li>
<li>addpacketnumber</li>
<li>addpacketchar</li>
<li>addpacketstring</li>
<li>packetnumber</li>
<li>packetchar</li>
<li>packetstring</li>
</ul>
<p>
Simply put, a buffer of 65507 bytes is created and these functions allow you to read off the data from the buffer or write new data to it.
If you've had any programming classes at all the usage of these functions should be fairly obvious.
</p>
<br>
<br>
<br clear=right>


<h1>METHODS</h1>

<h4>Open</h4>
<table class=function>
<tr><th>returns</th><td>boolean "connected"<td></tr>
<tr><th>parameters</th><td>string "address", number "port"</td></tr>
</table>
<p>
Opens a UDP connection to the server on the specified host and port.
If this fails the method returns a "false".
If it succeds it returns a "true".
</p>
<p>
The address can be a dotted ip address or a registered domain name or subdomain.
The port is typically a port number, but it will also accept some well known port names such as "whois".
</p>
<p>
Opening a connection resets the running error log.
</p>


<h4>Close</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Closes the current socket connection.
If the socket is already closed (by the remote server for example) you should
still perform a close on your local machine as well.
If, you attempt to open a socket, but it does not connect, then you do not have
to close it (but you can still issue a Close if you want to.)
</p>
<p>
Note that once a socket is closed the values of many properties, such as <em>bytesreceived</em> may become unavailable.
</p>


<h4>Send</h4>
<table class=function>
<tr><th>returns</th><td>integer "length"<td></tr>
<tr><th>parameters</th><td>string "text"</td></tr>
</table>
<p>
Sends a block string of data out to the remote server.
</p>


<h4>Recv</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Gets data from the remote server as a string.
</p>


<h4>SendCSV</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>string (comma seperated values)<td></tr>
</table>
<p>
For the more advanced among you, this can be very useful.
A byte of course is a binary value of 0 to 255 inclusive, and bytes are the foundation of all TCP/IP communications.
By specifying a string decimal numbers seperated by commas (for example "1,255,123,131,13,10,0"),
this function will convert them to bytes codes before sending them on.
</p>
<p>
Primarily this is of use with TELNET-type servers which use embedded byte-codes that have no keyboard equivilent.
You can also use it to build binary file formats, but that's a more complicated example.
</p>


<h4>RecvCSV</h4>
<table class=function>
<tr><th>returns</th><td>string (comma seperated values)</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Instead of receiving a purely text string, any data recved is decoding in a a string of comma seperated numbers.
The numbers represent bytes as values of 0 to 255 inclusive.
</p>


<h4>SendPacket</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Sends the binary data puffer.
</p>


<h4>RecvPacket</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Receives a UDP packet into a binary buffer.
</p>


<h4>packetclear</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Resets positions of binary packet and blank the packet buffer.
</p>


<h4>addpacketnumber</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>string "type" string "value"<td></tr>
</table>
<p>
Adds a number to the binary packet buffer.
type may be: BYTE, WORD, DWORD, int8, int16, int32, float32 or float64.
</p>


<h4>addpacketchar</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>character "char"<td></tr>
</table>
<p>
Adds a single character to the binary packet buffer.
</p>


<h4>addpacketstring</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>string<td></tr>
</table>
<p>
Adds an ascii string to the binary packet buffer.
<br>
<tt>As of v1.16 treated NULL terminated strings as C/C++ strings (NULLs terminate string).</tt>
</p>


<h4>addpacketstringN</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>string<td></tr>
</table>
<p>
Adds an ascii string to the binary packet buffer but without a following c-style NULL character.
Basically this is to allow VisualBasic-style strings that have prepended length variables.
<br>
<tt>As of v1.16 treated NULL terminated strings as VB strings (NULLs are preserved).</tt>
</p>


<h4>addpacketipport</h4>
<table class=function>
<tr><th>returns</th><td>string "ip" ("octet.octet.octet.octet"), number "port"</td></tr>
<tr><th>parameters</th><td>boolean "connected"<td></tr>
</table>
<p>
Inserts an IPv4 ip:port string into the packet stream.
</p>


<h4>packetnumber</h4>
<table class=function>
<tr><th>returns</th><td>number "num"</td></tr>
<tr><th>parameters</th><td>string "type"<td></tr>
</table>
<p>
Reads data from the binary packet buffer.
type may be: BYTE, WORD, DWORD, int8, int16, int32, float32 or float64.
</p>


<h4>packetchar</h4>
<table class=function>
<tr><th>returns</th><td>character "char"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Reads a single character from the binary packet buffer.
</p>


<h4>packetstring</h4>
<table class=function>
<tr><th>returns</th><td>string "text"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Reads an ascii string from the binary packet buffer.
</p>


<h4>packetstringN</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td>integer "length"<td></tr>
</table>
<p>
Reads in an ascii string from the binary packet buffer of the specified length.
This is to facilitate, among other things, the use of VisualBasic-style strings that used prepended length variables.
</p>


<h4>packetstringC</h4>
<table class=function>
<tr><th>returns</th><td>text</td></tr>
<tr><th>parameters</th><td>character "char"<td></tr>
</table>
<p>
Reads in an ascii string from the binary packet buffer until it encounters the specified character.
</p>


<h4>packetipport</h4>
<table class=function>
<tr><th>returns</th><td>string "ip" ("octet.octet.octet.octet"), number "port"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Extracts an IPv4 ip:port string from the packet stream.
</p>


<h4>ClearLog</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Clears the error log.
</p>




<br>
<br>
<br>
<h1>PROPERTIES</h1>

<p>
All properties are optional.
They can be extremely useful for optimizing the performance of your code however,
particular where high-performance, highly-responsive operation is required.
</p>


<h3>PUT</h3>

<h4>timeout</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>floating-point-number "seconds"<td></tr>
</table>
<p>
The timeout setting is very important to understand for peak performance.
The defines how long any of the Send, Recv, SendCSV or RecvCSV functions will wait for a response from the remote server before giving up.
This is a float point number representing the number of seconds.
Millisecond precision can be set using the fractional portion.
For example the default setting is 100milliseconds.
In ASP you would set this as: <tt>obj.timeout=0.100</tt>.
</p>
<p>
It is very important to note that because of internet congestion or other situations such as heavy server load
that you may not be able to receive the entire text of a transmission at a single time with the default setting of 100ms.
Adjust it up to whatever you feel is appropriate.
</p>
<p>
For gaming purposes this is essentially equal to the milliesecond ping times.
</p>


<h4>reposition</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>number "position"<td></tr>
</table>
<p>
Repositions index into binary packet.
</p>


<h3>GET (anytime)</h3>

<h4>description</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Description of this COM object.
</p>

<h4>copyright</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The copyright notice.
</p>

<h4>version</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The current version number.
</p>

<h4>Log</h4>
<table class=function>
<tr><th>returns</th><td>string</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns the error log string.
</p>

<h4>instance</h4>
<table class=function>
<tr><th>returns</th><td>number</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
If you code calls several instances of this COM into existance at once you can determine which instance you are talking to by calling this.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>


<h4>instances</h4>
<table class=function>
<tr><th>returns</th><td>number</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
See "instance".
Calling this returns the number of instances of this COM object that have been called into existance since your server has been rebooted.
</p>
<p>
Note: When using this COM in desktop software the instance number will reset itself when the software is closed and restarted.
When used in sever-side software, as long as the COM stays loaded in memory, then every time the COM is called the instances number will increase by one.
</p>
<p>
Instances/Instance are mainly of use with debugging/optimizing the COM instantation process.
</p>
<p>
This is an integer number, where the default first instance is always numbered "1".
</p>


<h3>GET (only when open)</h3>

<h4>timeout</h4>
<table class=function>
<tr><th>returns</th><td>floating-point-number "seconds"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns a floating-point-number indicating the current timeout setting in seconds.
For instance "3.50" indicates the functions will give up (timeout) after three and a half seconds.
</p>


<h4>localaddress</h4>
<table class=function>
<tr><th>returns</th><td>string "address"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns a string with the <em>address:port</em> url of the local end of the connection.
</p>


<h4>remoteaddress</h4>
<table class=function>
<tr><th>returns</th><td>string "address"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns a string with the <em>address:port</em> url of the remote end of the connection.
</p>


<h4>bytessent</h4>
<table class=function>
<tr><th>returns</th><td>integer "bytes"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The total number of bytes sent to the remote server.
</p>


<h4>bytesreceived</h4>
<table class=function>
<tr><th>returns</th><td>[integer:num]</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The total number of bytes received from the remote server.
</p>

<h4>udpsocket</h4>
<table class=function>
<tr><th>returns</th><td>integer</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The current socket (session) number being used.
</p>

<h4>senttimeout</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>floating-point-number "seconds"<td></tr>
</table>
<p>
If a RECV method times outs, this will tell you.
If it is 0 then the last RECV used did not time out.
Otherwise it is the seconds the method waited before giving up.
</p>
<p>
Timeout is used to dynamically adjust for network latency conditions.
How you do this of course is completely up to you.
</p>

<h4>receivedtimeout</h4>
<table class=function>
<tr><th>returns</th><td></td></tr>
<tr><th>parameters</th><td>floating-point-point "seconds"<td></tr>
</table>
<p>
If a RECV method times outs, this will tell you.
If it is 0 then the last RECV used did not time out.
Otherwise it is the seconds the method waited before giving up.
</p>

<h4>sendlength</h4>
<table class=function>
<tr><th>returns</th><td>integer</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
(Might be the length of the internal send buffer.)
</p>

<h4>recvlength</h4>
<table class=function>
<tr><th>returns</th><td>integer</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
(Might be the length of the internal recv buffer.)
</p>


<h4>messagelength</h4>
<table class=function>
<tr><th>returns</th><td>integer</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
(Might be the length of the udp buffer.)
</p>


<h4>buffersize</h4>
<table class=function>
<tr><th>returns</th><td>integer</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The size of the internal udp buffer: 65507.
</p>


<h4>kbpssending</h4>
<table class=function>
<tr><th>returns</th><td>floating-point-point</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The computed kilobytes per second of data sent.
</p>


<h4>kbpsreceiving</h4>
<table class=function>
<tr><th>returns</th><td>floating-point-number</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
The computed kilobytes per second of data received.
</p>


<h4>ping</h4>
<table class=function>
<tr><th>returns</th><td>integer "millisconds"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Ping is computed automatically for you.
Internally it is computed by simply starting a timer whenever a udp packet is sent and stopping it the next time you recieve a packet.
Because of this please be aware that if you send a udp then do a lot of computations inbetween that and when you attempt to recieve the packet that the ping numbers may be off.
</p>
<p>
This is in milliseconds.
</p>




<h4>packetlength</h4>
<table class=function>
<tr><th>returns</th><td>integer "bytes"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Length of binary packet.
</p>


<h4>packetposition</h4>
<table class=function>
<tr><th>returns</th><td>integer "bytes"</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Position into binary packet.
</p>


<h4>packetEOF</h4>
<table class=function>
<tr><th>returns</th><td>boolean</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns TRUE if packetposition GTE packetlength. Else FALSE.
</p>


<h4>is_connected</h4>
<table class=function>
<tr><th>returns</th><td>boolean</td></tr>
<tr><th>parameters</th><td><td></tr>
</table>
<p>
Returns TRUE if basic winsock and UDP connection opening sequences occured without any problems.
Generally only returns FALSE if their is a TCP/IP stack por network configuration problem.
</p>





<br>
<br>
<br>
<h1>VERSION HISTORY</h1>

<ul>

<li><b>2.2</b> August 30th 2012.
<p>
Compile for 64-bit support in addition to 32-bit.
</p>
<p>
For unknown reasons the separate <tt>classes\</tt> folder with common code between this a  few other projects was not bundled in the last uploaded version of this app. Thus, I have had to pull it from other sources. The various files were slightly out of temporal sync, thus I've had to rebuild the project more from scratch than anticipated.</p><p>
The 2.2 version pulls some of its sources from a partial port to Macintosh OS X I did years ago but never released.</p><p>
From now on, each project keeps it's own separate copy of any shared files.
Especially important given that it is going to be released on github and codeplex.
</p>
<p><b>This version should be considered possibly unstable as it has not been extensively retested.</b></p>
<p><b>TO DO:</b>
Make C# COM interop .NET DLL or perhaps pinvoke a c wrapped version.
Not interested in using C++/CLI.
</p>
</li>

<li><b>2.1</b> November 5th 2004.
<p>
Updated the C++ classes it shares with several other projects, so recompiled.
Cleaned up for the relaunch of the <a href="http://www.intrafoundation.com">Intrafoundation</a> web site.
</p>
</li>

<li><b>2.00</b> July 6th 2004.
<p>
Never released 2.00 but did today after a few tweaks and cleaning up the documentation.
The property "error" has become "Log" and a "ClearLog" function has been added.
</p>
<p>
NOTE: For compatibility with ColdFusion all "boolean" values are passed as "long" (Once again. Now I remember why it was originally doing that -- ColdFusion can't handle boolean's with COM objects.)
</p>
</li>

<li><b>2.00/1.18</b> April 23 2004.
<ol>
<li>Fixed inversion of returns/parameters notation in documents.</li>
<li>Added daytime and time protocol examples.</li>
<li>Added new Log class and extra debugging info.</li>
<li>Misc little tweaks to clean up code a bit.</li>
<li>Oh. Important. Fixed a bug (an oversight actually) that had "open" returning a number instead of a boolean like was stated.</li>
Thought about leaving it that way, but couldn't resist fixing it.</li>
The downside is this breaks some ASP code that's looking for a number to be returned.</li>
It now returns "True" or "False" as a boolean should.</li>
<li>Added instance and instances properties.</li>
<li>Added an application level thread-safe mutex. (So the COM can be used in application scope of CF or ASP without too much crashing.)</li>
<li>Changed version to 2.00 when I realized I had to change the COM interface for the additional functions.
Before 2.00 all versions used the interface "Intrafoundation.UDPCLient.1".
This version uses "Intrafoundation.UDPCLient.2" which is slightly different (new functions and a change to the open functions' return type.)
</li>
<li>Added high resolution timer code.</li>
<li>Optimized udp Revc function.</li>
<li>Added sendpackets and recvpackets stat.</li>
</ol>
</li>


<li><b>1.17</b> November 20th 2003.
<p>
<tt class=quote>
UDPClient Author: Eric Shufro URL: http://eric.shufro.com  Created: 9/6/2003 9:44:54 AM 

Maybe im doing it wrong, but addpacketstringN chr(128-142) excluding 129 and 141 dont work. Nor does chr(145-159) excluding chr(157). Very odd. Instead the udpclientcom sends chr(0) when any of those listed numbers that dont work appear. All other numbers between 0 and 255 work perfectly. There are 27 numbers that will not send and generate 0`s instead. Any ideas?
</tt><br>
</p>
</li>

<li><b>1.16</b> July 20th 2003.
<p>
Minor tweak to addpacketstring and addpacketstringN.
Cleaned up some docs.
</p>
</li>

<li><b>1.15 G</b> May 2003.
<p>
A few minor fixes to docs and code.
</p>
</li>

<li><b>1.12</b> Nov 15th 2001.
<p>
<ul>
<li>My ASP is a bit rusty, but... I added ASP examples for Half-life, RTCW, Quake3, STEF, etc after a bit of prodding by Sakke Huhmarniemi.</li>
<li>Fixed packetlength and packetposition bug that let "junk" number show up in asp if you weren't connected.</li>
<li>Added packetEOF property.</li>
</ul>
</p>
</li>

<li><b>1.11a</b> Oct 8th 2001.
<p>
SteelValor sent over some spare gaming gear for the gaming-list help the other day.
The attack v-1 gaming mouse pad is <a href="https://www.gamersport.com/SHOP/products_category.asp?CategoryID=17">*nice*</a>.
I mention this because I was trying it out in the new Quake3-based Return to Castle Wolfenstein (yes, I'm addicated to it -- so are a lot of us)...
and I kept killing this poor guy named <strong>captureman</strong> after the other folks left the server.
Over and over and over.
He finally just disconnected.
I feel bad about it. Poor guy.
These pads are evil. /-)
</p>
<p>
A few slight script changes.
Someone gave me an old copy of Tribes 1.0.
Apparently the code doesn't work very well with it or the 1.11 patch.
Hrm.
</p>
</li>

<li><b>1.11</b> Oct 2nd 2001.
<p>
Cleaned up the cfm a bit.
Added packetstringN, addpacketstringN and packetstringC functions to COM to handle visualbasic-style strings with prepended length variables.
This was done to more easily deal with the format of Starsiege: Tribes
(you could have simply used a loops of packetchar's).
</p>
<p>
Added some experimental Starsiege: Tribes code.
Since I don't actually own a copy... it's somewhat of an educated guess as to whether it works.
</p>
</li>

<li><b>1.10</b> Sept 21st 2001.
<p>
Added wolfenstein test (same as quake3).
Mulled over adding high-performance functions to batch send/recv for gamescry.
Forums at <a href="http://www.steelvalor.com/forum/">steelvalor</a>.
</p>
<p>
My game name, BTW, is <strong>TommyRaven</strong> or sometimes <strong>LT.TommyRaven</strong>.
</p>
</li>

<li><b>1.9</b> Sept 13th 2001.
<p>
Tightened up a lot of the udp class (the low-level class part of the COM).
Also straightened up several script bugs or oddities of the protocols in the scripts, especially with unreal.
Added some code by <a href="http://www.steelvalor.com">steelvalor</a>.
</p>
</li>

<li><b>1.8</b> Sept 9th/12th 2001.
<p>
Some of the scripts were upgraded, especially gamescry and unreal.
Added some experimental IP and Port packet features, but you probably shouldn't try to use them.
</p>
</li>

<li><b>1.7</b> Sept 6th 2001.
<p>Duh. Forgot to add a PING function. Fixed. Now every send/recv cycle has ping automatically computed for you.</p>
</li>

<li><b>1.6</b> Sept 5th 2001.
<p>Fixed an oddness in the half-life script that misreported mod byte sizes.</p>
<p>Also added GAME SCRY ;-> page.</p>
</li>

<li><b>1.5</b> Sept 4th 2001.
<p>Munged up the half-life code. Fixed. Misc other.</p>
</li>

<li><b>1.4</b> Sept 2nd 2001.
<p>Cleaned up examples.</p>
</li>

<li><b>1.3</b> Sept 2nd 2001.
<p>
Cleaned up packet functions.
I haven't as yet used the "packet" write/add functions at all so it's a guess as to whether they actually work or not.
</p>
</li>

<li><b>1.2</b> August 31th 2001.
<p>More cleanup.</p>
<p>
Binary field structuring/destructing functions where added to handle half-life.
Unlike all the other server query setups which send their data in clear text,
half-life sends it's data in binary c structs.
Efficient, but annoying to deal with.
</p>
<p>
While redesigning the website I'd completely forgotten that I'd decided not to make tcpclient/udpclient GPL.
Why? Because some folks want to use them in commerical apps and then sell the apps.
I really don't give a damn what most people do with this code as long as they make good use of it and don't try to claim that THEY wrote the original code (people do that sometimes).
If there was a GPL that allowed use in commerical apps without having to reveal the code that others wrap around it then that's what I'd use.
And how I'll assume you'll use it.
</p>
</li>

<li><b>1.1beta</b> August 30th 2001.
<p>
General cleanup to code and docs. Added Unreal derivitives. Looking for Baldur's Gate, etc info....
(btw, before you ask: I don't know what the yellow flower symbol is about. It just wanted to sit there so I let it.)</li>
Still reworking those damn docs....
reading the working scripts would probably be more informative.
</p>
</li>

<li><b>1.0alpha</b> August 29th/30th 2001.
<p>Started working on it again in the afternoon. Pretty much had it working later that night after trying a few different strategies. K.I.S.S. /-) The documentation is competely bogus at the moment... leftover from the tcpclient project folder. It's my experience that writing technical docs usually takes longer than writing the project itself.</p>
</li>

<li><b>0.1alpha</b> August 22nd 2001.
<p>Some folks at <a href="http://www.cnyonlinegamers.net/">http://www.cnyonlinegamers.net</a> asked if I could list server game stats. What the hell. Was going to have to write something similiar for another project soon anyway, sooo... Recreated the projects files.</p>
</li>

<li><b>0.0</b> - 1999 - 2001, shadow thought for tcpclient for years</li>

</ul>
<!-- END DESCRIPTION -->



<br clear=all>
<hr>
<div align=right>
Intrafoundation Software<br>
<small><tt>Making Atomic Warfare Fun Again</tt></small><br>
<br clear=all>
</div>

</body>
</html>

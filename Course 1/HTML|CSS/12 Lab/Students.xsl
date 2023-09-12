<xsl:stylesheet version="1.0"
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="html"/>
    <xsl:template match="/t">
        <table border="1">
            <xsl:for-each select="Student1">
                <tr>
                    <td bgcolor="green"><xsl:value-of select="."/></td>
                </tr>
            </xsl:for-each>
            <xsl:for-each select="Student2">
                <tr>
                    <td bgcolor="red"><xsl:value-of select="."/></td>
                </tr>
            </xsl:for-each>    
    </table>
    </xsl:template>     
</xsl:stylesheet>
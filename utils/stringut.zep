namespace Utils;

class StringUt
{
	/**
	*
	* StringUt::hasPrefix( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
	*
	* @param string hackstack 
	* @param string needle
	* @param boolean bIgnoreCase = false
	*
	*  return boolean
	*/
	public static function hasPrefix( string hackstack, string needle, boolean bIgnoreCase = false ) -> boolean
	{
		if unlikely hackstack == null || needle == null  {
			return false;
		}
			
		if false !== (bIgnoreCase ? stripos( hackstack, needle, 0 ) : strpos( hackstack, needle, 0 )){
			return true;
		}
		
		return false;
	}
	
	/**
	*
	* StringUt::hasSuffix( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
	*
	* @param string hackstack 
	* @param string needle
	* @param boolean bIgnoreCase = false
	*
	*  return boolean
	*/
	public static function hasSuffix(string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
	{
	    if unlikely ( strHackstack == null ||
        	strNeedle == null )
	    {
	        return false;
	    }
	    
	    int iHSLen = strlen( strHackstack );
	    int iStart = iHSLen - strlen( strNeedle );
	    
	    if( iStart > iHSLen || iStart < 0 )
	    {
	        return false;
	    }
	    
	    if( false !== ( bIgnoreCase ? stripos( strHackstack, strNeedle, iStart ) : strpos( strHackstack, strNeedle, iStart ) )) {
	        return true;
	    }
	    
	    return false;

	}
	
	/**
	*
	* StringUt::contains( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
	*
	* @param string hackstack 
	* @param string needle
	* @param boolean bIgnoreCase = false
	*
	*  return boolean
	*/
	public static function contains( string strHackstack, string strNeedle, boolean bIgnoreCase = false ) -> boolean
	{
		if unlikely ( strHackstack == null ||
	        	strNeedle == null )
		{
		        return false;
		}
	    
	    if( false !== ( bIgnoreCase ? stripos( strHackstack, strNeedle ) : strpos( strHackstack, strNeedle  ) )) {
	        return true;
	    }
	    
	    return false;
	}
}
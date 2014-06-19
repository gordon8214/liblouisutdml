package org.liblouis;

import java.io.File;

public final class LibLouis
{
  private static LibLouis singleInstance = null;
  private static boolean libraryLoaded = false;
  public static void loadLibrary(String libraryPath, String librarySuffix)
      throws Exception
  {
    if (libraryLoaded)
    {
      return;
    }
    if ((libraryPath == null) || (librarySuffix == null))
    {
      throw new Exception(
          "Could not load liblouis, libraryPath or librarySuffix not defined."
      );
    }
    System.load(new File(libraryPath, "liblouis" + librarySuffix).getAbsolutePath());
    libraryLoaded = true;
  }
  private LibLouis()
  {
  }
  public static LibLouis getInstance()
  {
    if (singleInstance == null)
      singleInstance = new LibLouis();
    return singleInstance;
  }
  /**
   * Get the size of widechar used by LibLouis.
   */
  public native int charSize();
  /**
   * Set the path for which liblouis will look for tables.
   */
  public native void setDataPath(String path);
  /**
   * Set the log file for liblouis.
   */
  public native void setLogFile(String fileName);
  /**
   * End the liblouis log file.
   */
  public native void logEnd();
  /**
   * Register a callback for liblouis logging.
   */
  public native void registerLogCallback(LogCallback cb);
  /**
   * Set liblouis logging level.
   */
  public native void setLogLevel(int level);
  /**
   * Add a new entry to a table.
   */
  public native boolean compileString(String tableList, String newEntry, String logFile);
  public native boolean translateString(String tableList, byte[] inbuf, int[] inlen, byte[] outbuf, int[] outlen, byte[]typeform, String logFileName, int mode);
  public native boolean translate(String tableList, byte[] inbuf, int[] inlen, byte[] outbuf, int[] outlen, byte[] typeform, int[] outputPos, int[] inputPos, int[] cursorPos, String logFileName, int mode);
  public native boolean hyphenate(String tableList, byte[] inbuf, int inlen, byte[] hyphens, String logFilename, int mode);
  public native boolean backTranslateString(String tableList, byte[] inbuf, int[] inlen, byte[] outbuf, int[] outlen, byte[] typeform, String logFileName, int mode);
  public native boolean backTranslate(String tableList, byte[] inbuf, int[] inlen, byte[] outbuf, int[] outlen, int[] outputPos, int[] inputPos, int[] cursorPos, byte[] typeform, String logFileName, int mode);
}


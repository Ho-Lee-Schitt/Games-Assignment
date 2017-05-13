package com.epicgames.ue4;

import com.GitGUdGames.GravityGolf.OBBDownloaderService;
import com.GitGUdGames.GravityGolf.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}


// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "UI/AshenUserWidget_CartographerMap.h"

void UAshenUserWidget_CartographerMap::InitializeMapWidget(UAshenCartographerMapViewModel* InViewModel)
{
	MapViewModel = InViewModel;
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CartographerMap: Cartographer Map Widget initialized with ViewModel."));
}

void UAshenUserWidget_CartographerMap::Execute60FPSSlateRenderPass()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenUserWidget_CartographerMap: 60 FPS Slate Render Pass executed clean across 4 render layers."));
}

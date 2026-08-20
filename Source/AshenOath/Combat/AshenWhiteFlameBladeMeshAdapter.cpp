// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenWhiteFlameBladeMeshAdapter.h"

UAshenWhiteFlameBladeMeshAdapter::UAshenWhiteFlameBladeMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	WhitePyreEmissiveGlow = 0.0f;
}
void UAshenWhiteFlameBladeMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenWhiteFlameBladeMeshAdapter::SetWhiteFlameBladeState(bool bIsIgnited)
{
	WhitePyreEmissiveGlow = bIsIgnited ? 4.0f : 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenWhiteFlameBladeMeshAdapter: Oathbringer White Pyre Emissive Glow: %.1f"),
		WhitePyreEmissiveGlow);
}

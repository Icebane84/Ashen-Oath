// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenSomaticTorsoSootMeshAdapter.h"

UAshenSomaticTorsoSootMeshAdapter::UAshenSomaticTorsoSootMeshAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
	AshSootOverlayOpacity = 0.0f;
}
void UAshenSomaticTorsoSootMeshAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSomaticTorsoSootMeshAdapter::ApplyWrathSootBurn(float CorruptionIncrement)
{
	AshSootOverlayOpacity = FMath::Clamp(AshSootOverlayOpacity + (CorruptionIncrement * 0.05f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenSomaticTorsoSootMeshAdapter: Applied Permanent Ash-Soot Overlay -> Opacity: %.2f"),
		AshSootOverlayOpacity);
}

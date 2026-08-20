// Copyright Phoenix Protocol. All rights reserved.

#include "VFXManager.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "NiagaraCommon.h"
#include "Kismet/GameplayStatics.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Engine/World.h"

UVFXManager::UVFXManager()
{
}

void UVFXManager::InitializeVFXManager(UGameInstance* GameInstance)
{
	if (!GameInstance) return;

	if (UAshenOath_GameEventSubsystem* GameEvents = GameInstance->GetSubsystem<UAshenOath_GameEventSubsystem>())
	{
		GameEvents->OnVfxRequested.AddDynamic(this, &UVFXManager::HandleVfxRequested);
	}
}

void UVFXManager::SpawnVFX(FName EffectName, FVector Position, FRotator Rotation)
{
	UWorld* World = GetWorld();
	if (!World) return;

	for (const FAshenVFXTemplate& Tmpl : VFXTemplates)
	{
		if (Tmpl.EffectName == EffectName)
		{
			if (Tmpl.NiagaraSystem)
			{
				UNiagaraFunctionLibrary::SpawnSystemAtLocation(
					World,
					Tmpl.NiagaraSystem,
					Position,
					Rotation,
					FVector(1.0f),
					true,
					true,
					ENCPoolMethod::AutoRelease
				);
			}
			else if (Tmpl.CascadeSystem)
			{
				UGameplayStatics::SpawnEmitterAtLocation(
					World,
					Tmpl.CascadeSystem,
					Position,
					Rotation,
					true
				);
			}
			break;
		}
	}
}

void UVFXManager::HandleVfxRequested(FName EffectName, FVector Position, FRotator Rotation)
{
	SpawnVFX(EffectName, Position, Rotation);
}

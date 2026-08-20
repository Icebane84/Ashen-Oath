// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "VFXManager.generated.h"

class UNiagaraSystem;
class UParticleSystem;

USTRUCT(BlueprintType)
struct FAshenVFXTemplate
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	FName EffectName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* NiagaraSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UParticleSystem* CascadeSystem;

	FAshenVFXTemplate()
		: EffectName(NAME_None)
		, NiagaraSystem(nullptr)
		, CascadeSystem(nullptr)
	{}
};

/**
 * UVFXManager
 * Central dispatcher that maps semantic visual effects requested from gameplay
 * to Niagara or Cascade system templates and manages spawn triggers.
 */
UCLASS(BlueprintType, Blueprintable)
class ASHENOATH_API UVFXManager : public UObject
{
	GENERATED_BODY()

public:
	UVFXManager();

	/** Initialize manager and bind to global request delegates */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void InitializeVFXManager(UGameInstance* GameInstance);

	/** Spawn visual effect at location */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void SpawnVFX(FName EffectName, FVector Position, FRotator Rotation);

private:
	UFUNCTION()
	void HandleVfxRequested(FName EffectName, FVector Position, FRotator Rotation);

private:
	UPROPERTY(EditAnywhere, Category = "VFX Settings", meta = (AllowPrivateAccess = "true"))
	TArray<FAshenVFXTemplate> VFXTemplates;
};

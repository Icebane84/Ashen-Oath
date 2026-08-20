// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityHallucinationVFXComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHallucinationVFXSpawnedSignature, FName, VFXEffectID, FVector, WorldLocation);

/**
 * UAshenSanityHallucinationVFXComponent
 *
 * Spawns dynamic peripheral eyes, shadow silhouette flashes, and void tendril glitches.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityHallucinationVFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityHallucinationVFXComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|HallucinationVFX")
	void SpawnPeripheralHallucination(FName VFXEffectID, FVector Offset);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HallucinationVFX|Events")
	FOnHallucinationVFXSpawnedSignature OnHallucinationVFXSpawned;
};

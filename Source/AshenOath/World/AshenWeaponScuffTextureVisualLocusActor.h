// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWeaponScuffTextureVisualLocusActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnScuffTextureUpdatedSignature, float, ScuffMaskBlend, bool, bIsFullyWorn);

/**
 * AAshenWeaponScuffTextureVisualLocusActor
 *
 * World Actor applying dynamic scuff texture masks to weapon meshes (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API AAshenWeaponScuffTextureVisualLocusActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenWeaponScuffTextureVisualLocusActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ScuffTexture")
	void UpdateScuffTextureBlend(float WearPercent);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ScuffTexture|Events")
	FOnScuffTextureUpdatedSignature OnScuffTextureUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ScuffTexture")
	float ActiveScuffMaskBlend = 0.0f;
};

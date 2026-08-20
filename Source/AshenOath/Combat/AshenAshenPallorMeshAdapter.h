// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAshenPallorMeshAdapter.generated.h"

/**
 * UAshenAshenPallorMeshAdapter
 * Modulates Kaelen's head and skin material instances, fading face skin to ghost-ash pallor and turning eyes to solid crimson slits at C >= 0.70.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAshenPallorMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAshenPallorMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float SkinPallorDesaturation = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float CrimsonEyeEmissive = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateUnchainedFacialMorphs(float CorruptionAmount);
};

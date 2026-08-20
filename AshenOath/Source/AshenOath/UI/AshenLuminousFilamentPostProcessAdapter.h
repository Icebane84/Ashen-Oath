// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLuminousFilamentPostProcessAdapter.generated.h"

/**
 * UAshenLuminousFilamentPostProcessAdapter
 * Modulates golden anamorphic lens flare bloom and chromatic dispersion around active woven memory filaments.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLuminousFilamentPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLuminousFilamentPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float FilamentBloomIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void ApplyFilamentBloom(float TensionScalar);
};

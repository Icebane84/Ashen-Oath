// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenIgnitedCutlassMeshAdapter.generated.h"

/**
 * UAshenIgnitedCutlassMeshAdapter
 * Modulates Garrett's twin cutlass weapon material instances, driving thermal flame emissive glow (0.0 to 3.0) and heat distortion when coated.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIgnitedCutlassMeshAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIgnitedCutlassMeshAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Visuals")
	float FlameEmissiveGlow = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void SetCutlassIgnitionState(bool bIgnited);
};

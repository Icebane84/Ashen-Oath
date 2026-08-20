// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualityShaderShiftComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDualityBlendRatioChanged, float, BlendRatio);

/**
 * UAshenDualityShaderShiftComponent
 * Dynamic shader transition blending real-world textures with Mindscape crystalline geometry during high debt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityShaderShiftComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualityShaderShiftComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Shaders")
	FOnDualityBlendRatioChanged OnBlendRatioChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Shaders")
	float CurrentDualityBlendRatio = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shaders")
	void SetDualityBlendRatio(float NewRatio);
};

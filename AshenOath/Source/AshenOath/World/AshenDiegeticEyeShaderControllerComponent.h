// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticEyeShaderControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEyeShaderGlowUpdatedSignature, float, EmissiveIntensity, FLinearColor, EyeGlowColor);

/**
 * UAshenDiegeticEyeShaderControllerComponent
 *
 * Component updating character eye shader glow/emissive intensity based on corruption and sanity.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticEyeShaderControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticEyeShaderControllerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EyeShader")
	void UpdateEyeGlowState(float SanityLevel, float CorruptionLevel);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EyeShader|Events")
	FOnEyeShaderGlowUpdatedSignature OnEyeGlowUpdated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EyeShader")
	float CalculatedEmissiveIntensity = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EyeShader")
	FLinearColor CalculatedEyeGlowColor = FLinearColor::Blue;
};

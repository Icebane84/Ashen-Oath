// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanityPostProcessComponent.generated.h"

class UCameraComponent;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UAshenOath_SanityComponent;

/**
 * UAshenSanityPostProcessComponent
 * Dynamically binds player Sanity state to Follow Camera Post-Process settings.
 * Interpolates horror lens parameters (distortion, desaturation) in real time.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanityPostProcessComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanityPostProcessComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	/** Base material template for the sanity post-process overlay */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanityVisuals")
	TObjectPtr<UMaterialInterface> OverlayMaterialTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanityVisuals")
	FName DistortionParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanityVisuals")
	FName DesaturationParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|SanityVisuals")
	float InterpolationSpeed;

private:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DynamicPostProcessMID;

	TWeakObjectPtr<UCameraComponent> CachedCameraComponent;
	TWeakObjectPtr<UAshenOath_SanityComponent> CachedSanityComponent;

	float CurrentDistortion;
	float CurrentDesaturation;
};

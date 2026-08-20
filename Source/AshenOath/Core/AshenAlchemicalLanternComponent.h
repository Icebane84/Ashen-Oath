// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalLanternComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLanternFuelChangedSignature, float, CurrentFuel, float, LightRadius);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLanternToggledSignature, bool, bIsLit);

/**
 * UAshenAlchemicalLanternComponent
 * Fluid-fueled lantern burning alchemical oils to reveal spectral runes and disperse shadow miasma.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalLanternComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalLanternComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Lantern|Events")
	FOnLanternFuelChangedSignature OnLanternFuelChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Lantern|Events")
	FOnLanternToggledSignature OnLanternToggled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Lantern")
	float MaxFuel = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "AshenOath|Lantern")
	float CurrentFuel = 100.0f;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|Lantern")
	bool bIsLanternLit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Lantern")
	float BurnRate = 1.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Lantern")
	float CalculatedLightRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Lantern")
	float SpectralLightRadius = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Lantern")
	void ToggleLantern(bool bLit);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Lantern")
	void RefuelLantern(float FuelAmount);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Lantern")
	void RefillFuel(float Amount);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Lantern")
	void ConsumeFuel(float DeltaTime);
};

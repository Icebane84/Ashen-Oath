// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHarmonicResonanceArmorShredComponent.generated.h"

/**
 * UAshenHarmonicResonanceArmorShredComponent
 * Serafina's silicon armor cracking component: channels harmonic light frequencies to shatter Geode-Lurker and crystalline threat plates.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHarmonicResonanceArmorShredComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenHarmonicResonanceArmorShredComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bArmorFractured = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float ShatterCrystallinePlates(float BaseArmor);
};

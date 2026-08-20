// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenGarrettAssassinationExecution.generated.h"

/**
 * UAshenGarrettAssassinationExecution
 * Implements Garrett's tactical assassination dash, volumetric smoke shroud, and armor-shredding acid damage.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettAssassinationExecution : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenGarrettAssassinationExecution();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Setup")
	float MaxDashRange = 850.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Balance")
	float ArmorShredDamage = 350.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Finisher | Balance")
	float BasePostureBreakAmount = 100.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen | Finisher | Execution")
	bool ExecuteAssassinationDash(AActor* GarrettActor, AActor* VictimEnemy);
};

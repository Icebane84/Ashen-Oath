// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenDefianceBladePlantGASAbility.generated.h"

/**
 * UAshenDefianceBladePlantGASAbility
 * Defiance choice ability: plants Oathbringer into the earth, converting 50% poise damage to physical hardening while spiking debt by +2.5.
 */
UCLASS()
class ASHENOATH_API UAshenDefianceBladePlantGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenDefianceBladePlantGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float PoiseHardeningRatio = 0.50f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float IntegrationDebtSpike = 2.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteDefiancePlant(AActor* KaelenActor);
};

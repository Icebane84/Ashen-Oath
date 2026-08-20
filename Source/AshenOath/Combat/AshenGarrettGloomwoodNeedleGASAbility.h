// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenGarrettGloomwoodNeedleGASAbility.generated.h"

/**
 * UAshenGarrettGloomwoodNeedleGASAbility
 * Garrett's chemical suppressant ability delivering a Gloomwood dampener needle to reduce Kaelen's corruption scaling by -0.25.
 */
UCLASS()
class ASHENOATH_API UAshenGarrettGloomwoodNeedleGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenGarrettGloomwoodNeedleGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Containment")
	float CorruptionDampeningAmount = 0.25f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	bool InjectGloomwoodDampener(AActor* GarrettActor, AActor* KaelenActor);
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenMartyrSolitaryParryGASAbility.generated.h"

class UAshenSoulPublisher;

/**
 * UAshenMartyrSolitaryParryGASAbility
 * Solo parry ability compiled by the Lens of Accountability (+10% parry frame tolerance,
 * but drains 5% companion trust and adds +0.05 dysregulation to UAshenSoulPublisher).
 */
UCLASS()
class ASHENOATH_API UAshenMartyrSolitaryParryGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenMartyrSolitaryParryGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Combat")
	float ParryWindowBonusRatio = 0.10f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Combat")
	float TrustDrainPerParry = 0.05f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Combat")
	bool ExecuteMartyrParry(float& OutTrustPenalty);

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};

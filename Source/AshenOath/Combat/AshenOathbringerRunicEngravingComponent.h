// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerRunicEngravingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRunicEngravingAppliedSignature, FName, RuneTag, float, BonusHolyDamage);

/**
 * UAshenOathbringerRunicEngravingComponent
 *
 * Component embedding physical holy runes into Oathbringer's fuller, granting elemental damage scaling (PRS-001 Oathbringer Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerRunicEngravingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerRunicEngravingComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|RunicEngraving")
	void EngraveHolyRune(FName RuneTag, float HolyDamageBonus = 40.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|RunicEngraving|Events")
	FOnRunicEngravingAppliedSignature OnRuneEngraved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|RunicEngraving")
	FName ActiveEngravedRune = FName(TEXT("Rune.WhiteFlameSun"));
};

// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonSecretPassageComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSecretPassageRevealedSignature, FVector, PassageLocation);

/**
 * UAshenDungeonSecretPassageComponent
 *
 * Interactive hidden wall / illusory passage component revealing secret rooms when struck or triggered.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonSecretPassageComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonSecretPassageComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SecretPassage")
	bool RevealPassage();

	UFUNCTION(BlueprintPure, Category = "AshenOath|SecretPassage")
	bool IsRevealed() const { return bIsRevealed; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SecretPassage|Events")
	FOnSecretPassageRevealedSignature OnSecretPassageRevealed;

private:
	bool bIsRevealed = false;
};

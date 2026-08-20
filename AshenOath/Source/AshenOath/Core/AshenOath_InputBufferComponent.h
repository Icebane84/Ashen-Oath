// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_InputBufferComponent.generated.h"

USTRUCT(BlueprintType)
struct FAshenBufferedInput
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "InputBuffer")
	FName ActionName;

	UPROPERTY(BlueprintReadOnly, Category = "InputBuffer")
	float Timestamp;

	FAshenBufferedInput()
		: ActionName(NAME_None)
		, Timestamp(0.0f)
	{}

	FAshenBufferedInput(FName InActionName, float InTimestamp)
		: ActionName(InActionName)
		, Timestamp(InTimestamp)
	{}
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_InputBufferComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_InputBufferComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Put an input action into the buffer. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|InputBuffer")
	void BufferAction(FName ActionName);

	/** Compatibility wrapper for input presses/releases. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|InputBuffer")
	void BufferInput(FName ActionName, bool bPressed);

	/** Checks if a specific action is currently in the buffer and valid. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|InputBuffer")
	bool HasBufferedAction(FName ActionName) const;

	/** Consumes the action if it exists in the buffer and is valid. Returns true if consumed. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|InputBuffer")
	bool ConsumeBufferedAction(FName ActionName);

	/** Clears the buffer completely. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|InputBuffer")
	void ClearBuffer();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "InputBuffer", meta = (AllowPrivateAccess = "true"))
	float BufferValidityDuration;

	FAshenBufferedInput CurrentBufferedInput;
};
